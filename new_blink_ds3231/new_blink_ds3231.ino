/*  PROJETO DE IRRIGAÇÃO CONTROLADO POR TEMPORIZADOR
 * 
 *  MAPEAMENTO DO HARDWARE
 *  ds321 ---> Arduino Nano
 *  
 *  vcc -----> 3,3V
 *  gnd -----> GND
 *  SDA -----> A4
 *  SCK -----> A5
 *  -----------------------------------------------------------
 *  MODULO RELE ---> Arduino Nano
 *  
 *  vcc ----> 5V
 *  gnd ----> GND
 *  IN1 ----> 4
 *  IN2 ----> Não conectado (próximo sinal de uma futura bomba)
 *  COM1----> Negativo da Bomba
 *  NO1 ----> Positivo da Bomba
 *  ----------------------------------------------------------
 * 
 * Autor: Arthur Barreto
 */

#include "RTClib.h" //INCLUSÃO DA BIBLIOTECA

// declaração de pino de saída, bomba 1
#define bomba1 4
#define bomba2 5

RTC_DS3231 rtc; //OBJETO DO TIPO RTC_DS3231
int h,m,s;
bool um,dois;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bomba1,OUTPUT);
  pinMode(bomba2,OUTPUT);
  digitalWrite(bomba1,LOW);
  digitalWrite(bomba2,LOW);
  um = false;
  dois = false;

} // end setup

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now(); //CHAMADA DE FUNÇÃO

  h = now.hour();
  m = now.minute();
  s = now.second();

  switch (h){
    case 17:
      um = true;
      break;
    default:
      um = false;
      break;
  } // end switch bomba 1

  switch (m){
    case 2:
      dois = true;
      break;
    case 4:
      dois = true;
      break;
    case 8:
      dois = true;
      break;
    default:
      dois = false;
      break;
  } // end switch bomba 2
  
  digitalWrite(bomba1,um);
  digitalWrite(bomba2,dois);
  
} // end loop
