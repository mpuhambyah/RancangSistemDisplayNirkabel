#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("KEYPAD LCD TEST"); 
}


void loop(){
  char key = customKeypad.getKey();
  Serial.print(key);
  lcd.setCursor(0, 1);
  if(key){
    lcd.setCursor(0, 0);
    lcd.print("               ");
    lcd.setCursor(0, 1);
    lcd.print("KEY= ");
    lcd.print(key);
    if(key=='1')
    {
      lcd.setCursor(0, 0);
      lcd.print("Sistem ON");
    }
    else if(key=='2')
    {
      lcd.setCursor(0, 0);
      lcd.print("Sistem OFF");
    }
    else if(key=='3')
    {
      for(int i=15;i>=-20;i--)
      {
        lcd.setCursor(i, 0);
        lcd.print("Selamat Menunaikan Ibadah Puasa ");
        delay(100);
      }
    }
  }  
}
