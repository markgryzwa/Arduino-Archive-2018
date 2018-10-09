
#include <Servo.h>
Servo panservo;

char serialInput;
int milliseconds;
int duration;


void setup() {
  // put your setup code here, to run once:
  panservo.attach(9);
  Serial.begin(9600);
  Serial.println("1 = 5min, 2=10, 3=30, 4 = 60");
  Serial.println("f = forward, r=reverse, z=zero, e=180");
}

void loop() {
  // put your main code here, to run repeatedly: 
  
    //Serial.println("1=5, 2=10, 3=30");  
    while(Serial.available() > 0) {
      serialInput = Serial.read();
    //Serial.print("I read ");
    //Serial.println(serialInput);
    if(serialInput >= '0' && serialInput <= '9') {
      setspeed(serialInput);
      Serial.print("duration = ");
      Serial.println(duration);
      }
      else if(serialInput >= 'a' && serialInput <= 'z') {
      moveit(serialInput);
      }
    }
/*    Serial.println("g = go");
    if(Serial.available() > 'a' && Serial.available() <= 'z') {
    serialInput = Serial.read();
    moveit(serialInput);
  }*/
}

//_____________________________________________

void moveit(char command) {
  switch(command) {
    case 'f':
      Serial.println("Rotating Clockwise");
      for(int Angle=0; Angle<=180; Angle++) {
        Serial.print("Current Angle ");
        Serial.println(Angle);
        panservo.write(Angle);
        delay(duration);
      }
    break;
  
    case 'r':
       Serial.println("Rotating Counter Clockwise");
      for(int Angle=180; Angle>=0; Angle--) {
        Serial.print("Current Angle ");
        Serial.println(Angle);
        panservo.write(Angle);
        delay(duration);
      }      
     break;
   
   case 'z':
       Serial.println("Returning to Zero");
       panservo.write(0);
     break;
   
   case 'e':
       Serial.println("Rotating to 180");
       panservo.write(180);
     break;  
   
   default:
        Serial.println("Invalid command");
          Serial.println("1 = 5min, 2=10, 3=30, 4 = 60");
           Serial.println("f = forward, r=reverse, z=zero, e=180");
   break;  
  }

}

// ________________________________________________

void setspeed(char command) {
  switch(command) {
    
    case '1':
      Serial.println("5 minute");
      //milliseconds = 300000;
      duration = 1667;
      break;
      
    case '2':
       Serial.println("10 minutes");
       //milliseconds = 10*60*1000;
       duration = 3333;
    break;
    
    case '3':
       Serial.println("30 minutes");
       //milliseconds = 30*60*1000;
       duration = 10000;
    break;
    
    case '4':
       Serial.println("60 minutes");
       duration = 20000;
       break;
    
    default:
       Serial.println("Invalid command");
         Serial.println("1 = 5min, 2=10, 3=30, 4 = 60");
      Serial.println("f = forward, r=reverse, z=zero, e=180");
       break;
  }  

}  
