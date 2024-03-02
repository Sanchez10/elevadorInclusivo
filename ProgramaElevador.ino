#include <Stepper.h> //Biblioteca do motor de passo
#include <LiquidCrystal.h> //Biblioteca do LCD

//Pinos do motor de passo
#define e1 10
#define e2 11
#define e3 12
#define e4 13

//Pinos do LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Definição de uma volta completa e definição da sequencia dos pinos do modulo Uln2003APG
const int passosPorGiro=64;
Stepper mp(passosPorGiro,e1,e3,e2,e4);

void setup() 
{
  lcd.begin(16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY. EM SUMA: UMA MATRIZ DE 16 COLUNAS E 2 LINHAS
  lcd.setCursor(0,0); //SETA A POSIÇÃO EM QUE O CURSOR INCIALIZA(LINHA 1) 
  lcd.print("ANDAR"); //ESCREVE A FRASE "APERTOU A TECLA" NA PRIMEIRA LINHA DO DISPLAY LCD  
  Serial.begin(9600);
}

void loop() 
{
  lcd.setCursor(0,1); //SETA A POSIÇÃO EM QUE O CURSOR RECEBE O TEXTO A SER MOSTRADO(LINHA 2)

  if ((analogRead(0)) < 80) 
  { //SE A LEITURA DO PINO FOR MENOR QUE 80, FAZ 
    lcd.print ("1"); //BOTÃO DIREITA
    Serial.println("Primeiro Andar");
    
    //Sentido horário
    motor(500,1,1,500,64);
    delay(3000);
    
    lcd.setCursor(0,1);
    lcd.print ("T");

    //Sentido anti horário
    motor(500,-1,1,500,64);
    delay(3000);
  }  
  else if ((analogRead(0)) < 200 & (analogRead(0)) > 80) 
  { //SE A LEITURA DO PINO FOR MENOR QUE 200, FAZ
    lcd.print ("2");  //BOTÃO CIMA
    Serial.println("Segundo Andar");
    
    //Sentido horário
    motor(500,1,1,500,128);
    delay(3000);
    
    lcd.setCursor(0,1);
    lcd.print ("T");

    //Sentido anti horário
    motor(500,-1,1,500,128);
    delay(3000);
  }  
  else if ((analogRead(0)) < 400 & (analogRead(0)) > 200)
  { //SE A LEITURA DO PINO FOR MENOR QUE 400, FAZ  
    lcd.print ("3"); //BOTÃO BAIXO
    Serial.println("Terceiro Andar");
    
    //Sentido horário
    motor(500,1,1,500,192);
    delay(3000);
    
    lcd.setCursor(0,1);
    lcd.print ("T");

    //Sentido anti horário
    motor(500,-1,1,500,192);
    delay(3000);
  }
}

void motor(int vel, int sentido, int voltas, int tmp, int passos)
{
  mp.setSpeed(vel); //RPM
  
  for(int i=0;i<passos*voltas;i++)
  {
    mp.step(passosPorGiro*sentido);
  }
  delay(tmp);
}
