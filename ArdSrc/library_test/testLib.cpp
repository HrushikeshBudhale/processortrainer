#include "testLib.h"
#include <Arduino.h>

extern int globalVar;
int variable = 20;

void testfunction(void)
{
    Serial.println("Test function");
}

void secondfunction(void)
{
    Serial.print("header constant: ");
    Serial.println(CONSTANT);

    Serial.print("header variable: ");
    Serial.println(variable);

    Serial.print("global variable: ");
    Serial.println(globalVar);
}
