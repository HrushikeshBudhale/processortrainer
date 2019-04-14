
int ri = 32;
long int rd = 341234;
int mi = 21;
long int md = 870987;
String msg;
int i = 0;
void setup()
{
    Serial.begin(115200);
    delay(3000);
}

void loop()
{
    while (i < 15)
    {
        msg = String(i) + " ";
        msg += String(ri) + ":";
        msg += String(rd) + " ";
        msg += String(mi) + ":";
        msg += String(md);
        Serial.println(msg);
        delay(500);
        i++;
    }
    delay(500);
}
