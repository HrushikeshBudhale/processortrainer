char inString[] = "FFFFFFFF\0";
char bufPos = 0;

void setup()
{
    Serial.begin(115200);
    Serial.println("Start!");
}

void loop()
{
    if (Serial.available())
        handleSerial();
}

void handleSerial()
{
    char inChar = (char)Serial.read();
    switch (inChar)
    {
    case 'd':
        Serial.println("comm. OK!");
        break;

    case ',':
        unsigned long value;
        inString[8] = '\0';
        value = strtoul(inString, (char **)'\0', 16);
        Serial.print("Received: ");
        Serial.println(value);
        bufPos = 0;
        break;

    default:
        inString[bufPos++] = inChar; // append number to string
        Serial.println("appending");
        break;
    }
}