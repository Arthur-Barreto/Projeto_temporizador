/*
  Avaliação Prática
  Disciplina:
  Professor:
  Aluna: Ana

  OBSERVAÇÕES

  O CIRCUITO SUGERIDO FOI ALTERADO PARA MELHOR FUNCIONAR O PU0SH BUTTON
  Na parte inferior entramos com 5v no pino da esquerda e no pino da 
  direita um resistor de 1kohm, sendo este ligado ao terra. Por fim,
  o pino superior da direita foi ligado na porta digital 2, assim como
  sugerido.

  Referencias:
  https://youtu.be/3IFcafUIkOM
  Acessado em 05/07/2021

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
  Acessado em 5/07/2021
  
*/

// definindo as portas dos leds brancos
#define w1 5
#define w2 6
#define w3 7
// definindo as portas dos leds azuis
#define b1 8
#define b2 9
#define b3 10
// definindo o push button
#define push_button 2
// definindo o slide button
#define slide_button 3

// ======================================================== //
// variaveis do sistema
int branco = 0,
    azul = 0,
    led,temp,
    l,t,tm,
    a,b,c,d;
String recebi;

void push_function ();
void slide_function ();

void setup() {
  // definindo os pinos como entrada ou saída de sinal
  // todos os leds como saída
  pinMode(w1,OUTPUT);
  pinMode(w2,OUTPUT);
  pinMode(w3,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(b3,OUTPUT);
  // iniciar a comunicação serial
  Serial.begin(9600);
  Serial.println("Digite um dado do formato XX>Z");
  // configurando as interrupções, o slide é em change, pois hora está em vcc e hora está em gnd
  // já o push é de LOW, ele terá leitura 0V qunado precionado e quando não não terá estado lógico
  attachInterrupt(digitalPinToInterrupt(push_button), push_function, RISING);
  attachInterrupt(digitalPinToInterrupt(slide_button), slide_function, CHANGE);

}

void loop() {
  // verificando dados da serial, função retorna o numero de caracteres digitados
    
  if (Serial.available () > 0){
    recebi = Serial.readString();
    a = recebi[0];
    b = recebi[1];
    c = recebi[2];
    d = recebi[3];

    // a,b,c e d estão com valores da tabela asc
    // 62 = ">"
    // 49 = 1
    // vai incrementado de 1 em 1 até o 9, sendo que
    // 57 = 9
    
    if (b == 62){
      // temos o formato mais generico, x>
      led = a;
      temp = c;
    }

    if (c == 62){
      // temos 10>, logo o C é ">"
      led = 10;
      temp = d;
    }
    
    // vamos organizar os dados que estão na tabela asc
    // essa quantidade de if é para saber o pino do led e o tempo certo

    if (led == 53){
      l = 5;
    }

    if (led == 54){
      l == 6;
    }

    if (led == 55){
      l = 7;
    }
    if (led == 56){
      l = 8;
    }
    if (led == 57){
      l = 9;
    }
    if (led == 10){
      l = 10;
    }
    if (temp == 49){
      t = 1;
    }
    if (temp == 50){
      t = 2;
    }
    if (temp == 51){
      t = 3;
    }
    if (temp == 52){
      t = 4;
    }
    if (temp == 53){
      t = 5;
    }
    
  // ========== aqui sabemos o led e o tempo ==================
  // convertendo o tempo para milisegundos

  tm = t*1000;
  digitalWrite(l,HIGH);

  // caso queira ver no serial os comandos dos leds descomente abaixo
  /*
  Serial.print(l);
  Serial.println(" está ligado");
  */
  delay(tm);
  digitalWrite(l,LOW);
  /*
  Serial.print(l);
  Serial.println(" está desligado");
  */
  // verificar o grupo de leds e incrementar o contador
  if ((l>=5) && (l<=7) && ((t>=1) && (t<=5))){
    branco ++;
  } 
  if ((l>=8) && (l<=10) && ((t>=1) && (t<=5))){
    azul ++;
  }

  Serial.println("Digite uma nova entrada do formato XX>Z");

  } // enf if serial
} // end loop

void push_function(){

  // vamos tratar o bocuing do push button, fazendo com que o 
  // arduino trate ele a cada 100 ms, assim, temos: 
  
  static unsigned long delayEstado;

  if ((millis() - delayEstado) > 100){
    delayEstado = millis();
    Serial.print(branco);
    Serial.println(" vezes que o grupo de leds branco foi acionado");
    Serial.print(azul);
    Serial.println(" vezes que o grupo de leds azul foi acionado");
    
  } // end if ajuste de boucing
} // fim funçao de interrupção push button

void slide_function (){
  
    branco = 0;
    azul = 0;
    
} // fim da função de interrupção do slide button
