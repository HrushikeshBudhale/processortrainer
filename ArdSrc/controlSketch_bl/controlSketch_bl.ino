#include "processor.h"
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// ============================= constants ==============================

#define SAMPLE_TIME 200000 // 0.2 sec
// #define DEVICES 4
#define EXT_CLK 1

#define CLKPIN 4   // P4
#define MODEPIN 16 // P16
#define FREQPIN 36 // SVP

// ========================== Global variables ===========================

// todo: add cntlop

// Time between each evaluation (if mode is internal)
long int clkDelay = 500000;

// To prevent debounce
unsigned long buttonTime;
unsigned long last_buttonTime;
unsigned long modeTime;
unsigned long last_modeTime;

char inString[] = "FFFFFFFF\0"; // char array to hold incoming data
char bufPos = 0;				// holds index of char in inString

boolean doneUpload = false;
char uploadPC = 0;		 // keeps track of PC while code upload
boolean clkMode = false; // false if MODEPIN is set to EXT_CLK

hw_timer_t *sampleTimer = NULL;
hw_timer_t *evaluateTimer = NULL;

extern unsigned long int prog_data[PROG_LEN]; // ! External variable

//###################### main Functions ############################

void setup()
{
	SerialBT.begin("ESP32test"); //Bluetooth device name
	// Serial.begin(115200);
	delay(5000);
	// Clear all previous unwanted data
	serialFlush();

	// Initialise Lookup Table
	initLookupTbl();

	setInterrupts();
	setTimers();
}

void loop()
{
	if (SerialBT.available())
		handleSerial();
}

//###################### Timer Functions ############################

void setTimers()
{
	createSampleTimer();
	createEvaluateTimer();
	// SerialBT.println("setting Timers");
}

void createSampleTimer()
{
	sampleTimer = timerBegin(0, 80, true);					 // timer_id = 0; divider=80; countUp = true;
	timerAttachInterrupt(sampleTimer, &onSampleTimer, true); // edge = true
	timerAlarmWrite(sampleTimer, SAMPLE_TIME, true);
	timerAlarmEnable(sampleTimer);
}

void createEvaluateTimer()
{
	evaluateTimer = timerBegin(1, 80, true);					 // timer_id = 0; divider=80; countUp = true;
	timerAttachInterrupt(evaluateTimer, &onEvaluateTimer, true); // edge = true
	timerAlarmWrite(evaluateTimer, clkDelay, true);
	timerAlarmEnable(evaluateTimer);
}

void onSampleTimer()
{
	long int val;
	val = analogRead(FREQPIN); // 0 - 4095
	val = map(val, 0, 4095, 10000, 100000);
	val *= 100; // 0.1s to 1s
	clkDelay = val;
}

void onEvaluateTimer()
{
	if (clkMode != EXT_CLK)
	{
		// SerialBT.println("freq eval");
		evaluate();
	}
	endEvaluateTimer();
}

void endEvaluateTimer()
{
	timerEnd(evaluateTimer);
	createEvaluateTimer();
}

//###################### Interrupt Functions ############################

void setInterrupts()
{
	// check initial toggle position
	pinMode(MODEPIN, INPUT);
	clkMode = digitalRead(MODEPIN);

	// attach change sensitive interrupt to mode pin
	pinMode(MODEPIN, INPUT_PULLUP);
	// if (clkMode != EXT_CLK)
	// SerialBT.println("Mode: internal");
	// else
	// SerialBT.println("Mode: ext_clk");

	attachInterrupt(digitalPinToInterrupt(MODEPIN), changeMode, CHANGE);

	// interrupt at rising edge of clkpin
	pinMode(CLKPIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(CLKPIN), buttonISR, FALLING);
	// SerialBT.println("in setInterrupt");
}

// ISR to chage clock type (internal or external)
void changeMode()
{
	modeTime = millis();
	if (modeTime - last_modeTime > 250)
	{
		clkMode = !clkMode;
		// SerialBT.println("changeMode");
		last_modeTime = modeTime;
	}
}

// ISR to run function at button press
void buttonISR()
{
	buttonTime = millis();
	if (buttonTime - last_buttonTime > 250)
	{
		// SerialBT.println("buttonISR");
		if (clkMode == EXT_CLK)
		{
			// SerialBT.println("button eval");
			evaluate();
		}
		last_buttonTime = buttonTime;
	}
}

//###################### serial Functions ############################

void serialFlush()
{
	while (Serial.available() > 0)
	{
		char t = Serial.read();
		delay(1);
	}
}
void handleSerial()
{
	char inChar = (char)SerialBT.read();
	if (doneUpload)
	{
		switch (inChar)
		{
		case 'u': // starting to upload new code
			doneUpload = false;
			clearProg();
			// SerialBT.println("Starting Upload");
			break;

		case 'e': // execute next instruction
			// SerialBT.println("evaluating");
			if (clkMode == EXT_CLK)
			{
				// SerialBT.println("serial eval");
				evaluate();
			}
			break;

		case 'p': // ! for testing only
			printMems();
			break;

		case 'r': // Reset memories
			// SerialBT.println("Resetting");
			reset();
			break;
		}
	}
	else // if code is being uploaded
	{
		switch (inChar)
		{
		case 'd':		  // done uploading
			uploadPC = 0; // reset to 0
			bufPos = 0;
			// SerialBT.println("Upload Complete");
			reset();
			displayProgram();
			doneUpload = true;
			break;

		case ',': // instruction complete
			inString[8] = '\0';
			prog_data[uploadPC] = strtoul(inString, (char **)'\0', 16);
			// SerialBT.print("Received: ");
			// SerialBT.println(prog_data[uploadPC]);
			uploadPC++; // increment to store at next position
			bufPos = 0;
			break;

		default:
			inString[bufPos++] = inChar; // append number to string
			break;
		}
	}
}

void clearProg()
{
	for (int i = 0; i < PROG_LEN; i++)
		prog_data[i] = 0;
}

// testing function
void displayProgram()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			// SerialBT.print("\t");
			// SerialBT.print(prog_data[i + (j * 5)]);
		}
		// SerialBT.println();
	}
}
