
  int tone1 =1200;
int tone2 =900;
int duration =400;
int repeat =7;
int c; 
int pin =8;


void setup() {
  // put your setup code here, to run once:


}

void loop() {
  

  // put your main code here, to run repeatedly: 
  c = 0;
  while(c < repeat) {
    tone(pin, tone1, duration);
    //noTone(8);
    delay(duration);
    tone(pin, tone2, duration);
    //noTone(8);
    delay(duration);
    c++;
  }
  while(1);
  
}
