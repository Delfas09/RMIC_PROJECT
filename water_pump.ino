/*
 * AJ Alves (aj.alves@zerokol.com)
*/
//https://blog.zerokol.com/2013/03/water-pump-with-arduino.html
#define PUMP_PIN 2 // Water Pump Pin
 
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); // Serial Port setup
  pinMode(PUMP_PIN, OUTPUT); // Set pin as OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PUMP_PIN, HIGH); // Set pin HIGH
  Serial.println("The Water Pump is ON!");
  delay(3000); // esperar 3 segundos
  digitalWrite(PUMP_PIN, LOW); // Set pin LOW
  Serial.println("The Water Pump is OFF!");
  delay(3000); // Wait 3 seconds
}
