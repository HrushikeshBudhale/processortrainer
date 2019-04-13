#include <Arduino.h>
#line 1 "c:\\Users\\HRUSHIKESH\\Desktop\\proj\\ArdSrc\\hwTimer_test\\hwTimer_test.ino"
#line 1 "c:\\Users\\HRUSHIKESH\\Desktop\\proj\\ArdSrc\\hwTimer_test\\hwTimer_test.ino"
hw_timer_t *timer = NULL;

#line 3 "c:\\Users\\HRUSHIKESH\\Desktop\\proj\\ArdSrc\\hwTimer_test\\hwTimer_test.ino"
void onTimer();
#line 16 "c:\\Users\\HRUSHIKESH\\Desktop\\proj\\ArdSrc\\hwTimer_test\\hwTimer_test.ino"
void startTimer();
#line 24 "c:\\Users\\HRUSHIKESH\\Desktop\\proj\\ArdSrc\\hwTimer_test\\hwTimer_test.ino"
void endTimer();
#line 30 "c:\\Users\\HRUSHIKESH\\Desktop\\proj\\ArdSrc\\hwTimer_test\\hwTimer_test.ino"
void setup();
#line 36 "c:\\Users\\HRUSHIKESH\\Desktop\\proj\\ArdSrc\\hwTimer_test\\hwTimer_test.ino"
void loop();
#line 3 "c:\\Users\\HRUSHIKESH\\Desktop\\proj\\ArdSrc\\hwTimer_test\\hwTimer_test.ino"
void onTimer()
{
	static unsigned int counter = 1;

	Serial.print(millis());
	Serial.println(" ms");

	if (counter == 10)
		endTimer();

	counter++;
}

void startTimer()
{
	timer = timerBegin(0, 80, true);			 // timer_id = 0; divider=80; countUp = true;
	timerAttachInterrupt(timer, &onTimer, true); // edge = true
	timerAlarmWrite(timer, 1000000, true);		 //1000 ms
	timerAlarmEnable(timer);
}

void endTimer()
{
	timerEnd(timer);
	timer = NULL;
}

void setup()
{
	Serial.begin(115200);
	startTimer();
}

void loop() {}

