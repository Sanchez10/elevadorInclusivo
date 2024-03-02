// Código para Sistema de Áudio Indicador
// Desenvolvido para instalação em elevadores
// Um projeto Usinainfo (www.usinainfo.com.br)
 
#include "SoftwareSerial.h" // Inclui a biblioteca SoftwareSerial.h
#include "DFRobotDFPlayerMini.h" // Inclui a biblioteca DFRobotDFPlayerMini.h
 
int andar1 = 3; // Declara andar 1 como pino digital 3
int andar2 = 4; // Declara andar 2 como pino digital 4
int andar3 = 5; // Declara andar 3 como pino digital 5
 
//Inicia a comunicação serial nos pinos 10 (RX) e 11(TX)
SoftwareSerial mySoftwareSerial(10, 11);
 
// Declara o módulo DFPlayer
DFRobotDFPlayerMini myDFPlayer;
 
// Fixa os parâmetros iniciais
char buf;
int pausa = 0;
int equalizacao = 0;
 
void setup() 
{
 
  pinMode(andar1, INPUT); // Configura a porta digital 3 como entrada
  pinMode(andar2, INPUT); // Configura a porta digital 4 como entrada
  pinMode(andar3, INPUT); // Configura a porta digital 5 como entrada
 
  //Comunicacao serial com o modulo
  mySoftwareSerial.begin(9600);
 
  // Inicializa as funções do módulo DFPlayer
  myDFPlayer.begin(mySoftwareSerial);
 
  //Configurações iniciais
  myDFPlayer.setTimeOut(500); //Timeout serial 500ms
  myDFPlayer.volume(25); // Volume 30 (1-31)
  myDFPlayer.EQ(0); // Equalizacao normal
}
 
void loop() 
{
 
  //Aguarda a entrada de dados pela serial
  while (Serial.available() > 0) 
  {
    buf = Serial.read();
 
    //Reproducao
    if ((buf >= '1') && (buf <= '7')) 
      { // Limita as faixas possíveis
        buf = buf - 48;
        myDFPlayer.play(buf); // Reproduz a música selecionada
      }
  }
 
  if (digitalRead(andar1)) 
  { // Se reconhecer andar1
    myDFPlayer.play(1); // Seleciona faixa 1
    delay(3000); // Reproduz por 3s antes de parar
  }
  else 
  {
    myDFPlayer.stop(); // Se não reconhecer andar1 um não reproduz
  }
 
  if (digitalRead(andar2)) 
  { // Se reconhecer andar2
    myDFPlayer.play(2); // Seleciona faixa 2
    delay(3000); // Reproduz por 3s antes de parar
  }
  else 
  {
    myDFPlayer.stop(); // Se não reconhecer andar2 um não reproduz
  }
 
  if (digitalRead(andar3)) 
  { // Se reconhecer andar3
    myDFPlayer.play(3); // Seleciona faixa 3
    delay(3000); // Reproduz por 3s antes de parar
  }
  else 
  {
    myDFPlayer.stop(); // Se não reconhecer andar3 um não reproduz
  }
}
