/*
Recharge tone example

 http://www.arduino.cc/en/Tutorial/Tone4

 */

void setup() {

}

void loop() {
  // turn off tone function for pin 8:
  
  int i=0;
  while(i<4){
  // play a note on pin 6 for 200 ms:
  tone(6, 400, 200);
  delay(400);
  i++;
  }
delay(500);
  i=0;
  while(i<5){
    tone(6,800,100);
    delay(400);
    i++;
  }
delay(500);
i=0;
  while(i<6){
    tone(6,1200,100);
    delay(1200);
    i++;
  } 

delay(500); 
   i=0;
  while(i<5){
    tone(6,800,50);
    delay(55);
    tone(6,1200,50);
    delay(55);
    i++;
  }
  while(1);


}
