

#include <Servo.h>
Servo panservo;

int startAngle = 0;
int endAngle = 180;
int currentAngle = startAngle;
int stepSize = 2;
int wait = 50;      // 20 ms/step
float time = 180.0/2*50/1000;

char keyCommand;      // read from the serial monitor


void setup() {
  // put your setup code here, to run once:
    
  panservo.attach(9);    // attach the pan servo to pin 9
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly: 
  
  while (Serial.available()>0) {
   
    keyCommand = Serial.read();
    Serial.print("keypress = ");
    Serial.println(keyCommand);
    
    switch(keyCommand){
      case 'g':
      Serial.println("Moving 0 to 180");
      //rotate
      for (int i = currentAngle; i <= endAngle; i=i+stepSize) {
        Serial.print("Current angle = ");
        currentAngle = i;
        panservo.write(currentAngle);
        Serial.println(currentAngle);
        delay(wait);
      }      
      break;
      
      case 'r':
      Serial.println("Moving 180 to 0");
      //rotate back to start angle
      for(int i =currentAngle; i >= startAngle; i=i-stepSize) {
        Serial.print("Current Angle = ");
        currentAngle = i;
        panservo.write(currentAngle);
        Serial.println(currentAngle);
        delay(wait);
      }
      break;
      
      case 'i':
      if(wait > 10) {
        wait = wait - 10;
      }
      break;
      
      case 'd':
         wait = wait + 10;
      break;
      
      
      default:
      break;
    }
    Serial.println("g=0 to 180, r=180 to 0 i=increase speed, d=decrease speed");
    Serial.print("Current delay = ");
    Serial.println(wait);
    Serial.print("   Total time = ");
    time = float(180.0/stepSize*wait/1000.0);
    Serial.print(time);
    Serial.println(" seconds");
  } 
    
}
