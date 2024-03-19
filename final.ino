
#include <Stepper.h>

// Define number of steps per revolution
#define STEPS 700 
#define PWM D1
// Define pins for the motor coils
const int motorPin1 = D5;
const int motorPin2 = D6;
const int motorPin3 = D7;
const int motorPin4 = D8;

Stepper myStepper(STEPS, motorPin1, motorPin3, motorPin2, motorPin4);
                         //variavel do sensor de temperatura e humidade

void setup() {
  Serial.begin(9600);
  pinMode(PWM,OUTPUT);
  digitalWrite(PWM,LOW);
  myStepper.setSpeed(20); //1 rpm
}

// the loop function runs over and over again forever
void loop() {
  int hum=400;
  Serial.print("Moisture Sensor Value:");
  hum=analogRead(A0);
  Serial.println(hum);
  if (hum>=300)
  {
    Serial.println("Bou rodar pa um lado");
    digitalWrite(PWM,HIGH);
    myStepper.step(STEPS); // do 2510 steps -- corresponds to 1/4 revolution in one minute
    delay(1000); //wait for one second
    Serial.println("Agora po outro");
    myStepper.step(-STEPS); 
    delay(1000);// Wait for two seconds (to demonstrate the active low LED)
  }else
  {
    digitalWrite(PWM,LOW);
  }

}
