

#include <Servo.h>
Servo panservo;

float startAngle = 0.0;
float endAngle = 180.0;
float currentAngle = startAngle;
float stepSize = 0.0;
int wait = 50;      // 20 ms/step
int totalTime = 30;     // total time in seconds
float time = 180.0/2*50/1000;
int steps = 0;

char keyCommand;      // read from the serial monitor


void setup() {
  // put your setup code here, to run once:
    
  panservo.attach(9);    // attach the pan servo to pin 9
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly: 
  steps = 100 * totalTime;
  stepSize = (endAngle - startAngle) / steps;
  
  while(currentAngle <= endAngle) {
    Serial.print("Current Angle = ");
    Serial.println(int (currentAngle));
    currentAngle = currentAngle+stepSize;
    delay(10);
    panservo.write(currentAngle);
    
  }
  
}  

