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
// incluindo biblioteca para comunicação i2c e do modulo de tempo
#include <Wire.h>
#include <DS3231.h>
// declaração de pino de saída, bomba 1
#define bomba1 4
#define bomba2 5

// instanceando o modulo de tempo
RTClib myRTC;

// variáveis aux
int h,m,s;

void setup() {
    Serial.begin(57600);
    Wire.begin();
    delay(500);
    Serial.println("Nano Ready!");
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    digitalWrite(bomba2,LOW);
    digitalWrite(bomba2,LOW);
} // end setup

void loop() {
  delay(1000);

  DateTime now = myRTC.now();
  
  h = now.hour();

  Serial.println(h);

} // end loop
