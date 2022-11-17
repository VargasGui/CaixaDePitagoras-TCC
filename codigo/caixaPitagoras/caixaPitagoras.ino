#include <LiquidCrystal.h>
int resulttot;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
int buzzer = 10;

void setup(){
  
    lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  int num1 = random(2,2); //minimo, maximo de cada algarismo 
  int num2 = random(5,5);
  int result = num1 * num2;
  String mult = String(num1) + " x " + String(num2) + " = ";
  lcd.print(mult);
  delay(1000);
  resulttot = 10; //forçando para teste
  lcd.print("10");
  delay(500);
  if(resulttot == num1*num2){
    lcd.clear();
    lcd.print("CORRETO");
    tone(buzzer, 5000);
    delay(1000);
    noTone(buzzer);
  }
    
  lcd.clear();
  delay(1000);

}
