#include <virtuabotixRTC.h>

/* Arduino Nano
 * Moduto RTC, teste inicial
 * Arthur Barreto
 * 20/06/2021
 */

// --- definição dos pinos ---
#define clk    6
#define data   7
#define rst    8
// ===========================================
// constantes aux para implementar o horário
#define s      0
#define m      31
#define h      16
#define d_sem  1
#define d_mes  20
#define mes    8
#define a      2021
// ===========================================
virtuabotixRTC myRTC(clk,data,rst);
// ===========================================
//--- funções ---
void DS1302();
void week(int dayW);
// ===========================================
void setup() {
  Serial.begin(9600);
  // carregar o código uma vez para salvar as 
  // configurações iniciais, depois comentar a
  // linha a baixo e carregar novamente o código
  // myRTC.setDS1302Time(s,m,h,d_sem,d_mes,mes,a);
} // END SETUP

void loop() {
  DS1302();
  
} // END LOOP

// ============================================

void DS1302(){
  myRTC.updateTime();

  // imprime informações
  Serial.print(" -> ");
  week(myRTC.dayofweek);
  Serial.print(" | ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print(" | ");
  if (myRTC.hours < 10) Serial.print("0");
  Serial.print(myRTC.hours);
  Serial.print(":");
  if (myRTC.minutes < 10) Serial.print("0");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  if (myRTC.seconds < 10) Serial.print("0");
  Serial.println(myRTC.seconds);
  delay(1000);
  
} // END DS1302

void week(int dayW){

  switch(dayW){
    case 1: Serial.print("Dom");break;
    case 2: Serial.print("Seg");break;
    case 3: Serial.print("Ter");break;
    case 4: Serial.print("Qua");break;
    case 5: Serial.print("Qui");break;
    case 6: Serial.print("Sex");break;
    case 7: Serial.print("Sab");break;
  } // END SWITCH
} // END WEEK
