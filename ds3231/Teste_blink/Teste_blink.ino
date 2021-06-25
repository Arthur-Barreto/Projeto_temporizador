
// incluindo biblioteca para comunicação i2c e do modulo de tempo
#include <Wire.h>
#include <DS3231.h>

// instanceando o modulo de tempo
RTClib myRTC;

// variaveis aux
bool state = false;
int h;

void setup() {
    Serial.begin(57600);
    Wire.begin();
    delay(500);
    Serial.println("Nano Ready!");
    pinMode(13,OUTPUT);
} // end setup

void loop() {
  delay(1000);

  DateTime now = myRTC.now();

  h = now.hour();
  Serial.println(h);

  if (h == 9){
    state = !state;
    Serial.println(state);
    digitalWrite(13,state);
    delay(500);
  } // end if
} // end loop
