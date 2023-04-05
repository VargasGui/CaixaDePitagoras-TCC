
//BIBLIOTECAS
#include <Key.h>
#include <Keypad.h>
#include <Stepper.h>
#include <LiquidCrystal_I2C.h>

//CRIAÇÕES DE VARIÁVEIS
int acertos =0;
int erros =0;
int num1, num2, result;

//DECLARAÇÃO MOTOR DE PASSO
const int stepsPerRevolution = 2048;  // VALOR DE PASSOS PARA UMA VOLTA.
Stepper myStepper(stepsPerRevolution,10 , 11, 12, 13); //PINOS CONECTADOS

//DECLARAÇÃO LCD (L2C)
LiquidCrystal_I2C lcd(0x27, 16, 2); // L2C ENDEREÇO 0X27, 16 COLUNAS E 2 LINHAS.


//DECLARAÇÃO TECLADO
const byte LINHAS = 4; //4 LINHAS
const byte COLUNAS = 4; //4COLUNAS
//MATRIZ DO TECLADO
const char TECLAS_MATRIZ[LINHAS][COLUNAS] = { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
}; 
byte PINOS_LINHAS[LINHAS] = {9, 8, 7, 6}; //PINOS CONECTADOS LINHA
byte PINOS_COLUNAS[COLUNAS] = {5, 4, 3, 2}; //PINOS CONECTADOS COLUNA

//ATRIBUINDO FUNCIONALIDADE AO TECLADO
Keypad teste = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS);
                               
//NOSTAS MUSICAIS DO BUZZER
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

void setup(){
  
    //LCD
  
  lcd.init(); // INICIALIZA O LCD
  lcd.backlight(); //INICIALIZA A LUZ DE FUNDO
  
  //MOTOR DE PASSO
  randomSeed(analogRead(A0));
  myStepper.setSpeed(10); 
  
    
   lcd.setCursor(4,0);
   lcd.print("Caixa  de");
   lcd.setCursor(4,1);
   lcd.print("Pitagoras");
   delay(5000);
   for (int posicao = 0; posicao < 17; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(100);
  }
   lcd.clear(); 

   lcd.setCursor(20,0);
   lcd.print("Sejam");
   lcd.setCursor(17,1);
   lcd.print("Bem-Vindos!!");
   for (int posicao = 0; posicao < 15; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(100);
  }
   delay(3000);
   for (int posicao = 0; posicao < 17; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(100);
  }
}


void loop(){
  
    lcd.clear();
    lcd.print("Escolha Sua Fase");
    lcd.setCursor(1,1);
    lcd.print("A ---> B ---> C");
  
  String tecla ; 
  tecla=lerValor(); 
  
  num1=0,num2=0; 
  
  while(num1==0 && num2==0){
     
    
    if(tecla == "A"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fase A Escolhida");
      lcd.setCursor(0,1);
      lcd.print("La Vamos Nos!!");
      delay(2000);
      
      
        for(int i=0; i<5; i++){
          num1 = random(1, 5);
          num2= random(1,5);
          condicoes();
          
        }
        resultado();
      }

    else if(tecla == "B"){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Fase B Escolhida");
        lcd.setCursor(0,1);
        lcd.print("La Vamos Nos!!");
        delay(2000);
      
        for(int i=0; i<5; i++){
          num1 = random(5, 9);
          num2= random(5,9);
          condicoes();
        }
        resultado();
      }
      
    else if(tecla == "C"){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Fase C Escolhida");
        lcd.setCursor(0,1);
        lcd.print("La Vamos Nos!!");
        delay(2000);
      
        for(int i=0; i<5; i++){
          num1 = random(6, 11);
          num2= random(6,11);
          condicoes();
        }
        resultado();
      }
        
      
     else{
         lcd.clear();
         lcd.print("Fase invalida");
         delay(2000);
         lcd.clear();
         loop(); 
      }
   }  
}//FIM DO void loop()

void resultado(){
        
        if(acertos >= 3){
          lcd.clear();
          lcd.setCursor(4,0);
          lcd.print("Parabens!!");
          lcd.setCursor(0,1);
          lcd.print("Voce Acertou ");
          lcd.print(acertos);
          lcd.print("!");
          delay(3000);
          for (int posicao = 0; posicao < 20; posicao++)
          {
            lcd.scrollDisplayLeft();
            delay(100);
          }
          lcd.clear();
          lcd.setCursor(4,0);
          lcd.print("Receba");
          lcd.setCursor(2,1);
          lcd.print("Seu Premio!");
          
           myStepper.step(-512); 
          delay(5000);
          acertos=0;
          erros=0;
          loop();
        }
        else if(erros >= 3){
          lcd.clear();
          lcd.setCursor(4,0);
          lcd.print("Oh Nao!");
          lcd.setCursor(1,1);
          lcd.print("Voce Errou ");
          lcd.print(erros);
          lcd.print("!");
          delay(3000);

          for (int posicao = 0; posicao < 20; posicao++)
          {
            lcd.scrollDisplayLeft();
            delay(100);
          }
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("Tente");
          lcd.setCursor(3,1);
          lcd.print("Novamente!");
          delay(5000);
          acertos=0;
          erros=0;
          loop();
        }

}
      
void condicoes(){

String mult = String(num1) + " x " + String(num2) + " = ";
  lcd.clear();
  lcd.print(mult);
  
int leitura_usuario = lerValor().toInt();
  lcd.setCursor(0,1);
  result = num1 * num2;
  
    if(result == leitura_usuario){
      lcd.print("CORRETO!!");
      acertos++;
      tone(10,NOTE_E6,125);
        delay(130);
        tone(10,NOTE_G6,125);
        delay(130);
        tone(10,NOTE_E7,125);
        delay(130);
        tone(10,NOTE_C7,125);
        delay(130);
        tone(10,NOTE_D7,125);
        delay(130);
        tone(10,NOTE_G7,125);
        delay(125);
        noTone(10);
        delay(1000);
}
  else{
    lcd.print("ERRADO!! R=" + String(result));
    erros++;
    tone(10, 20000);
    delay(2000);
    noTone(10);
  }

}//FIM VOID CONDICOES


String lerValor(){
  String myString = "";
  
  char keyPressed = teste.getKey();
  
  
  //FUNCAO PARA DAR ENTER
  while ((keyPressed != '#') && (keyPressed != 'A') && (keyPressed != 'B') && (keyPressed != 'C')){
    keyPressed = teste.getKey();
  //FUNCAO PARA INUTILIZAR
    if ((keyPressed != NO_KEY) && (keyPressed != '#')&& (keyPressed != '*')&& (keyPressed != 'D')) {
      myString.concat(keyPressed);
      
      if((keyPressed != 'A') && (keyPressed != 'B') && (keyPressed != 'C')) { //OCULTA AS TECLAS A,B,C DO LCD POREM ELAS FUNCIONAM NORMAL!
      lcd.print(keyPressed);
      }
      
      tone(10, 8000);
      delay(80);
      noTone(10);  
      }     
   }  
      return(myString);  
} //FIM FUNCAO LERVALOR
