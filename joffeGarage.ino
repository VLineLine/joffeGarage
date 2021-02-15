#include <AccelStepper.h>
#include <Ultrasonic.h>

//Stepper
#define AIN2 3
#define AIN1 4
#define STBY 5
#define BIN2 6
#define BIN1 7

#define steps_open -250

//Ultrasonic sensor
#define HC_VCC 11
#define HC_TRIG 10
#define HC_ECHO 9
#define HC_GND 8

AccelStepper stepper_motor(AccelStepper::FULL4WIRE, AIN2, AIN1, BIN2, BIN1);
Ultrasonic ultrasonic(HC_TRIG, HC_ECHO);

void setup() {
  
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
  digitalWrite(13, OUTPUT);
  
  stepper_motor.setMaxSpeed(400);
  stepper_motor.setAcceleration(800);
  stepper_motor.setSpeed(60);
  stepper_motor.moveTo(0);

  //Setup ultrasonic sensor
  pinMode(HC_VCC, OUTPUT);
  digitalWrite(HC_VCC, HIGH);
  pinMode(HC_GND, OUTPUT);
  digitalWrite(HC_GND, LOW);
}

void loop() {
  if(stepper_motor.currentPosition()==0){
    if (ultrasonic.read()<9)
    {
      stepper_motor.moveTo(steps_open);
      digitalWrite(STBY,HIGH);
    }
    else
    {
      digitalWrite(STBY, LOW);
      delay(100);
    }
  }
  else if(stepper_motor.currentPosition()==steps_open)
  {
    if (ultrasonic.read()>12 & analogRead(A0)<100)
    {
      stepper_motor.moveTo(0);
      digitalWrite(STBY,HIGH);
    }
    else
    {
      delay(100);    
    }
  }

  stepper_motor.run();
}
