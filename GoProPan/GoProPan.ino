
#include <Servo.h>
Servo panservo;

int rotationTimeMinutes;
int rotationTimeSeconds;
int rotationTimeMilliseconds;
int millisecondsPerDegree;
int startAngle = 0;
int endAngle = 180;
int currentAngle = 0;


byte serialInput;


void setup() {
  // put your setup code here, to run once:
  panservo.attach(9);    // use pin 9 for the pan servo drive
  Serial.begin(9600);
  panservo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly: 

while(Serial.available() >= 0) {
  setspeed();
  moveit();
  moveit();
  while(1){}
}
}


void setspeed() {

  Serial.println("1 - 1 minute, 2 - 2 minutes, 3 - 5 minutes");
  Serial.println("4 - 15 minutes, 5 = 30 minutes, 6 = 60 minutes");
  //Serial.flush();
  delay(100);
  if(Serial.available() >0) {
    serialInput = Serial.read();
    Serial.print("I received ");
  Serial.println(serialInput);
  }
 
  switch(serialInput) {
    case '1':
    Serial.println("1 minute rotation");
    rotationTimeMilliseconds = 60 * 1000;
    millisecondsPerDegree = 180/rotationTimeMilliseconds;
    break;
    
    case '2':
    Serial.println("2 minute rotation");
    rotationTimeMilliseconds = 120 * 1000; 
    millisecondsPerDegree = 180/rotationTimeMilliseconds;  
    break;
    
    case '3':
    Serial.println("5 minute rotation");
    rotationTimeMilliseconds = 5 * 60 * 1000; 
    millisecondsPerDegree = 180/rotationTimeMilliseconds;     
    break;
    
    case '4':
    Serial.println("15 minute rotation");
    rotationTimeMilliseconds = 15 * 60 * 1000; 
    millisecondsPerDegree = 180/rotationTimeMilliseconds;     
    break;
    
    case '5':
    Serial.println("30 minute rotation");
    rotationTimeMilliseconds = 30 * 60 * 1000; 
    millisecondsPerDegree = 180/rotationTimeMilliseconds;     
    break;
    
    case '6':
    Serial.println("60 minute rotation");
    rotationTimeMilliseconds = 60 * 60 * 1000; 
    millisecondsPerDegree = 180/rotationTimeMilliseconds;     
    break;
    
    default:
    //setspeed();
    break;
    
    Serial.print(millisecondsPerDegree);
    Serial.println(" ms/degree");
    Serial.println("");
    
  }
  
}

void moveit() {
  
  Serial.println("g = 0 to 180, r = Jump to 0, e= Jump to 180, c = 180 to 0");
  //Serial.flush();
  serialInput = Serial.read();
  Serial.print("I received ");
  Serial.println(serialInput);
  
  switch(serialInput) {
   
    case 'g':
    currentAngle = 0;
    for(currentAngle; currentAngle<=180; currentAngle++) {
      panservo.write(currentAngle);
      Serial.print("Current Angle = ");
      Serial.println(currentAngle);
      delay(millisecondsPerDegree);
    }
    break;
    
    case 'r':
    currentAngle = 0;
    panservo.write(currentAngle);
    Serial.print("Current Angle = ");
    Serial.println(currentAngle);
    delay(500);   
    break;
    
    case 'e':
    currentAngle = 180;
    panservo.write(currentAngle);
    Serial.print("Current Angle = ");
    Serial.println(currentAngle);
    delay(500);     
    break;
    
    case 'c':
    currentAngle = 180;
    for(currentAngle; currentAngle>=0; currentAngle--) {
      panservo.write(currentAngle);
      Serial.print("Current Angle = ");
      Serial.println(currentAngle);
      delay(millisecondsPerDegree);
    }
    break;
    
    default:
    //moveit();
    break;
    
  } 
}
