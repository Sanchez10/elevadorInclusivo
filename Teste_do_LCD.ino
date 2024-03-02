#include <LiquidCrystal.h> //INCLUSÃO DE BIBLIOTECA
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //PORTAS DO ARDUINO QUE SÃO UTILIZADAS PELO SHIELD KEYPAD DISPLAY LCD
  
void setup()
{  
  lcd.begin(16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY. EM SUMA: UMA MATRIZ DE 16 COLUNAS E 2 LINHAS
  lcd.setCursor(0,0); //SETA A POSIÇÃO EM QUE O CURSOR INCIALIZA(LINHA 1) 
  lcd.print("ANDAR"); //ESCREVE A FRASE "APERTOU A TECLA" NA PRIMEIRA LINHA DO DISPLAY LCD  
}  
  
void loop()
{  
  lcd.setCursor(0,1); //SETA A POSIÇÃO EM QUE O CURSOR RECEBE O TEXTO A SER MOSTRADO(LINHA 2)
  
  if ((analogRead(0)) < 80) 
  { //SE A LEITURA DO PINO FOR MENOR QUE 80, FAZ 
    lcd.print ("1"); //ESCREVE NO LCD O TEXTO DIREITA
    lcd.setCursor(0,1);
    delay(3000);
    lcd.print ("T");
  }  
  else if ((analogRead(0)) < 200) 
  { //SE A LEITURA DO PINO FOR MENOR QUE 200, FAZ
    lcd.print ("2");  //ESCREVE NO LCD O TEXTO CIMA
    lcd.setCursor(0,1);
    delay(3000);
    lcd.print ("T");
  }  
  else if ((analogRead(0)) < 400)
  { //SE A LEITURA DO PINO FOR MENOR QUE 400, FAZ  
    lcd.print ("3"); //ESCREVE NO LCD O TEXTO BAIXO
    lcd.setCursor(0,1);
    delay(3000);
    lcd.print ("T");
  }
}
