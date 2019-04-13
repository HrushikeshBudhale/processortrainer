void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
}
 
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog ADC1_0:
  long int sensorValue = analogRead(36);
  // print out the value you read:
  sensorValue = map(sensorValue, 0, 4095, 10000, 100000); // 0.1s to 1s
  sensorValue *= 100;
  Serial.println(sensorValue);
  delay(100);        // delay in between reads for stability
}
