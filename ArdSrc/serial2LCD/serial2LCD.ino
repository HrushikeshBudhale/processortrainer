#include <LedControl.h>
//#include <TimeAlarms.h>

#define DEVICES 4

// DataIn, CLK, LOAD, No. of displays
//LedControl lc = LedControl(12,14,15,DEVICES);
LedControl lc = LedControl(12,11,10,DEVICES); // For arduino

void initAllDisplay(void);
void updateDisplay(String inString);
void setNum(int device, unsigned long int Data);

void setup() {

    Serial.begin(57600);
    while (!Serial.available()); // wait for serial port to connect. Needed for native USB port only
    initAllDisplay();
    Serial.println("Serial Communication OK!");
    delay(5);
    Serial.println("Enter data to display.");
    delay(5);
}

void loop() {
    if(Serial.available() > 0) {
        String inString ="";
        while (Serial.available() > 0) {
            int inChar = Serial.read();
            inString += (char)inChar;
            if (inChar == '\n') {
                updateDisplay(inString);
                break;
            }
        }
    }
    else
        delay(10);
}

void initAllDisplay(void){
    for(int i=0; i<DEVICES; i++){
        lc.shutdown(i,false);
        lc.setIntensity(i,8);
        lc.clearDisplay(i);
        for(int j=0; j<8; j++){
            lc.setDigit(i,j,0,false);
        }
    }
}

void updateDisplay(String msg){
    int from;
    int device;
    unsigned long int Data;
    while(msg.indexOf(":") != -1){
        from = msg.indexOf(":");
        device = (msg.substring(from-1)).toInt();
        Data = (msg.substring(from+1)).toInt();
        setNum(device,Data);
        
        from = msg.indexOf(",");    // if next value is present
        if(from != -1)  // get next value
            msg = msg.substring(from+1);
        else
            break;
    }
}

void setNum(int device, unsigned long int Data){
    Serial.println("Setting num!!");
    for(int i=7; i>=0; i--){
    //for(int i=0; i<=7; i++){
        lc.setDigit(device,i,(Data%10),false);
        if(Data != 0)
            Data /= 10;
    }
}
