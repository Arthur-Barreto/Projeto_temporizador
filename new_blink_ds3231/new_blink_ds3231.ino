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

char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

int h;
bool um;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bomba1,OUTPUT);
  //pinMode(bomba2,OUTPUT);
  digitalWrite(bomba1,LOW);
  //digitalWrite(bomba2,LOW);
  um = false;
  //dois = false;

} // end setup

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now(); //CHAMADA DE FUNÇÃO

  h = now.hour();
  
  switch (h){
    case 5:
      um = true;
      break;
    default:
      um = false;
      break;
  } // end switch bomba 1
/*
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
  */
  digitalWrite(bomba1,um);
  //digitalWrite(bomba2,dois);

  Serial.print("Data: "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(now.day(), DEC); //IMPRIME NO MONITOR SERIAL O DIA
  Serial.print('/'); //IMPRIME O CARACTERE NO MONITOR SERIAL
  Serial.print(now.month(), DEC); //IMPRIME NO MONITOR SERIAL O MÊS
  Serial.print('/'); //IMPRIME O CARACTERE NO MONITOR SERIAL
  Serial.print(now.year(), DEC); //IMPRIME NO MONITOR SERIAL O ANO
  Serial.print(" / Dia: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]); //IMPRIME NO MONITOR SERIAL O DIA
  Serial.print(" / Horas: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(now.hour(), DEC); //IMPRIME NO MONITOR SERIAL A HORA
  Serial.print(':'); //IMPRIME O CARACTERE NO MONITOR SERIAL
  Serial.print(now.minute(), DEC); //IMPRIME NO MONITOR SERIAL OS MINUTOS
  Serial.print(':'); //IMPRIME O CARACTERE NO MONITOR SERIAL
  Serial.print(now.second(), DEC); //IMPRIME NO MONITOR SERIAL OS SEGUNDOS
  Serial.println(); //QUEBRA DE LINHA NA SERIAL
  delay(1000); //INTERVALO DE 1 SEGUNDO
  
} // end loop
