/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
#define PWM D1



void setup() {
  Serial.begin(9600);
  pinMode(PWM,OUTPUT);
  digitalWrite(PWM,LOW);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Bou rodar");
  digitalWrite(PWM,HIGH);
  delay(1000);                      // Wait for a second
  digitalWrite(PWM,LOW);
  delay(1000); 
  
  Serial.print("Moisture Sensor Value:");
  Serial.println(analogRead(A0));
  delay(100);  
}
