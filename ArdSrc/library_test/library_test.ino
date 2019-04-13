#include "testLib.h"
int globalVar = 200;

void setup()
{
    Serial.begin(115200);
    delay(5000);
    testfunction();
    secondfunction();
    Serial.print("src:");
    Serial.println(variable);
    Serial.print("src:");
    Serial.println(globalVar);
    Serial.print("src:");
    Serial.println(CONSTANT);
}

void loop() {}