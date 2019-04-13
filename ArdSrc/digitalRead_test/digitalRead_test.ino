#define inputPIN 4 // P4
#define modePIN 16 // P16
void setup()
{
    pinMode(modePIN, INPUT);
    Serial.begin(115200);
}

void loop()
{
    Serial.println(digitalRead(modePIN));
    delay(500);
}