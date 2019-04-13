#define SAMPLE_TIME 200000 // 0.2 sec
// #define DEVICES 4
#define EXT_CLK 1
#define CLKPIN 1
#define MODEPIN 2
#define FREQPIN 36

long int clkDelay = 500000;

String inString = ""; // a String to hold incoming data

String outString = ""; // a String to hold outgoing data

boolean doneUpload = false;
char uploadPC = 0;		 // keeps track of PC while code upload
boolean clkMode = false; // false if MODEPIN is set to EXT_CLK

hw_timer_t *sampleTimer = NULL;
hw_timer_t *evaluateTimer = NULL;

unsigned long int prog_data[20]; // 32 bit

void setup()
{
	Serial.begin(115200);
	while (Serial.available() <= 0)
		;

	setInterrupts();
	setTimers();
}

void loop() {}

//###################### Timer Functions ############################

void setTimers()
{
	createSampleTimer();
	createEvaluateTimer();
	Serial.println("setting Timers");
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
	// Serial.println(clkDelay);
}

void onEvaluateTimer()
{
	if (doneUpload && clkMode != EXT_CLK)
	{
		// evaluate();
		Serial.println("freq eval");
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
	attachInterrupt(digitalPinToInterrupt(MODEPIN), changeMode, CHANGE);

	// interrupt at rising edge of clkpin
	pinMode(CLKPIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(CLKPIN), buttonISR, RISING);
	Serial.println("in setInterrupt");
}

// ISR to chage clock type (internal or external)
void changeMode()
{
	clkMode = !clkMode;
	Serial.println("changeMode");
}

// ISR to run function at button press
void buttonISR()
{
	Serial.println("buttonISR");
	if (doneUpload && clkMode == EXT_CLK)
	{
		// evaluate();
		Serial.println("button eval");
	}
}

//###################### serial Functions ############################

void serialEvent()
{
	char inChar = (char)Serial.read();
	if (doneUpload)
	{
		switch (inChar)
		{
		case 'u': // starting to upload new code
			Serial.println("Starting Upload");
			doneUpload = false;
			break;
		case 'e': // execute next instruction
			Serial.println("evaluating");
			if (clkMode == EXT_CLK)
			{
				// evaluate();
				Serial.println("button eval");
			}
			break;
		case 'r': // Reset memories
			Serial.println("Resetting");
			// todo: Add reset function (include doneUpload = true)
			break;
		}
	}
	else // if code is being uploaded
	{
		switch (inChar)
		{
		case 'd':
			uploadPC = 0; // reset to 0
			// todo: Add reset function (include doneUpload = true)
			doneUpload = true;
			Serial.println("Upload Complete");
			break;

		case ',':
			Serial.print("Received: ");
			Serial.println(inString);
			// todo: convert hex string to long int
			inString = ""; // empty string
			uploadPC++;	// increment to store at next position
			break;

		default:
			inString += inChar; // append number to string
			Serial.println("appending");
			break;
		}
	}
}
