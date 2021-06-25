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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bomba1,OUTPUT);
  pinMode(bomba2,OUTPUT);
  digitalWrite(bomba1,LOW);
  digitalWrite(bomba2,LOW);

} // end setup

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now(); //CHAMADA DE FUNÇÃO

  h = now.hour();
  m = now.minute();
  s = now.second();

  if (h == 16){
    digitalWrite(bomba1,HIGH);
    Serial.println("BOMBA1 LIGA");
  }
  if (h != 16){
    digitalWrite(bomba1,LOW);
    Serial.println("BOMBA1 DESLIGA");
  }
  
  /*
  if ((m > 45) && (m < 50)){
    digitalWrite(bomba2,HIGH);
    Serial.println("BOMBA2 LIGA");
  }

  if ((m <=45) && (m >= 50)){
    digitalWrite(bomba2,LOW);
    Serial.println("BOMBA2 DESLIGA");
  }
  */
  
} // end loop
