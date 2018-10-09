// KITT Knight Rider Light effect math
int numLeds = 10;
int width = 4;
int last;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // countup
  for(int i=0; i <= (numLeds-width); i++) {
    Serial.println("Leds lit now");
    for(int x=0; x<width; x++) {
      Serial.println(x+i);
    }
    Serial.println();
    Serial.println();
    delay(200);
  }

  
// countdown
Serial.println("Countdown");
  for(int i= (numLeds-width); i>=0; i--) {
     Serial.println("Leds lit now");
    for(int x=0; x<width; x++) {
      Serial.println(x+i);
    }
    Serial.println();
    Serial.println();
    delay(200);   
  }
}
