
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int minMicrosec = 600;
int neutralMicrosec = 1500;
int maxMicrosec = 2300;
int timePerStep = 100;      // milliseconds
int ledStatus = 0;
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
} 
 
void loop() 
{ 
  //while(!Serial){}
  
  for(pos = minMicrosec; pos <= maxMicrosec; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.writeMicroseconds(pos);    // tell servo to go to position in variable 'pos' 
    Serial.print(pos);
    Serial.println(" microsec");
    if(ledStatus == 0){
      ledStatus = 1;
      digitalWrite(13, HIGH);
    }
    else {
      ledStatus=0;
      digitalWrite(13, LOW);
    }
    delay(timePerStep);                       // waits 15ms for the servo to reach the position 
  } 
    delay(1000);
    myservo.writeMicroseconds(minMicrosec);  // return to start
    //while(1){}
    
  //for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  //{                                
  //  myservo.write(pos);              // tell servo to go to position in variable 'pos' 
  //  delay(15);                       // waits 15ms for the servo to reach the position 
  //} 
} 
