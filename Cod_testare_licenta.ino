#include <Stepper.h>
#include <Servo.h>

#define STEPS 2048
#define MotorPin 3  
// Define pins for Arduino Uno
Stepper circular(STEPS, 8, 10, 9, 11);
Stepper left_right(STEPS, 4, 6, 5, 7);
Servo myServo;

bool CircularhasRun = false; 
bool Left_RighthasRun = false; 
bool Back_Forth_hasRun = false; // Flag to ensure function runs only once

void moveCircularStepper() {
  circular.setSpeed(15);  // Set speed to 15 RPM
  circular.step(2048); 
}

void moveLeft_RightStepper() {
  left_right.setSpeed(15);  // Set speed to 15 RPM
  left_right.step(2048);
}

void moveForthServo() {
  myServo.write(140);
}

void moveBackServo() {
  myServo.write(0);
}

void setup() {
  myServo.attach(MotorPin);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);
  
}

void loop() {
  delay(5000);
 if (!CircularhasRun) {  // Check if function has already run
    moveCircularStepper();
    CircularhasRun = true;  // Set flag to true so it doesn't run again
  }
  

  /*if (!Back_Forth_hasRun) {  // Check if function has already run
    moveForthServo();
    delay(1000);
    moveBackServo();
    Back_Forth_hasRun = true;  // Set flag to true so it doesn't run again
  }*/
  
  
 /*if(!Left_RighthasRun) {
    moveLeft_RightStepper();
    Left_RighthasRun = true;
  }*/

 
  
}
