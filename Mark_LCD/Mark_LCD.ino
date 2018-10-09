//
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,20,4);  // set the LCD address to 0x3f for a 16 chars and 4 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("Mark Gryzwa");
  delay(1000);
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(10,0);
  lcd.print("Time:");
  lcd.setCursor(6,1);
  lcd.print("F");
  lcd.setCursor(18,1);
  lcd.print("ms");
  lcd.setCursor(0,3);
  lcd.print("Text goes here");
  
}


void loop()
{
 int temp=random(100);
 printTemp(temp);
 printTime();
 delay(1000);
}


void printTemp(int var) {
  lcd.setCursor(1,1);
  lcd.print("     ");
  lcd.setCursor(1,1);
  lcd.print(var);
}

void printTime() {
  lcd.setCursor(11,1);
  lcd.print("       ");
  lcd.setCursor(11,1);
  lcd.print(millis());
}

