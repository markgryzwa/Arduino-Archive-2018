/*  The following is the template for creating designs that
 *  run on the cigar box controller made by Mark Gryzwa
 *  2 Analog pots
 *  2 SPDT switches
 *  2 pushbutton switches
 *  1 speaker
 *  1 buzzer
 */


#include <Servo.h>
Servo Servo1;
Servo Servo2;

// analog pins
const int leftPot = 0;
const int rightPot = 2;

// digital pins
const int sw1Up = 0;
const int sw1Down = 1;
const int sw2Up = 2; 
const int sw2Down = 3;
const int button1 = 4;
const int button2 = 5;
const int led2 = 6;
const int led3 = 7;
const int led4 = 8;
const int buzzer = 9;
const int speaker = 12;
const int led1 = 13;

// pwm pins for servo
const int servo1Pin = 10;
const int servo2Pin = 11;

// variables
int sw1UpStatus;
int sw1DownStatus;
int sw2UpStatus;
int sw2DownStatus;
int button1Status;
int button2Status;
int leftPotValue;
int rightPotValue;


void setup() {
  // put your setup code here, to run once:
  pinMode (sw1Up, INPUT);
  pinMode (sw1Down, INPUT);
  pinMode (sw2Up, INPUT);
  pinMode (sw2Down, INPUT);
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (speaker, OUTPUT);

  Servo1.attach(servo1Pin);
  Servo2.attach(servo2Pin);
 }

// ---------------------------------------------------------
void loop() {
  
  readPots();
    leftPotValue = map(leftPotValue, 0, 1023, 1000, 2000);
      Servo1.writeMicroseconds(leftPotValue);
    rightPotValue = map(rightPotValue, 0, 1023, 0, 170);  
      Servo2.write(rightPotValue);
  
  readSwitches();
    digitalWrite(led1, button1Status);
    digitalWrite(led2, button2Status);
    digitalWrite(led3, sw1UpStatus);
    digitalWrite(led4, sw1DownStatus);

  delay(50);
}


// ---------------------------------------------------------
void readSwitches() {
  sw1UpStatus = digitalRead(sw1Up);
  sw1DownStatus = digitalRead(sw1Down);
  sw2UpStatus = digitalRead(sw2Up);
  sw2DownStatus = digitalRead(sw2Down);
  button1Status = digitalRead(button1);
  button2Status = digitalRead(button2);
}
// ---------------------------------------------------------
void readPots()  {
  leftPotValue = analogRead(leftPot); 
  rightPotValue = analogRead(rightPot);
}

