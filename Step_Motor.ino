
#include <Stepper.h>

#define STEPS 2038 // o numero de steps numa revolução do motor (28BY-48)

Stepper stepper(STEPS, blue IN1, yellow IN3, white IN2, orange IN4)

void setup() {
  // put your setup code here, to run once:

}
void rodar(){
  // put your main code here, to run repeatedly:
  stepper.setSpeed(1); //1 rpm
  Stepper.step(510); // do 2510 steps -- corresponds to 1/4 revolution in one minute
  delay(1000); //wait for one second
  stepper.step(-510)
}
void loop() {


}
