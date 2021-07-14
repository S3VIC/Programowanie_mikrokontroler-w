//definicja zmiennych dla pinów obsługujących połączenia arduino ze sterownikiem
#include<SoftwareSerial.h>

SoftwareSerial BTserial(2,3); //Rx|Tx // ustwienie pinu 2,3 jako piny komunikujące się z modułem BT

const int IN1=5;
const int IN2=4;
const int ENA=6;

const int IN3=8;
const int IN4=7;
const int ENB=9;
//zmienna, w której przechowywany będzie znak odebrany przez moduł BT
//char c = ' ';

void setup() {
     //Serial.begin(9600); //do testów komunikacji BT
     //serial.begin(9600); // monior szeregowy wykorzystywany w przypadku sprawdzania komunikacji pomiędzy płytkami
     //arduino poprzez np. przesyłanie pojedycznych znaków
     BTserial.begin(9600); //inicjalizacja monitora BT
     
     pinMode(IN1, OUTPUT);
     pinMode(IN2, OUTPUT);
     pinMode(ENA, OUTPUT);

     pinMode(IN4, OUTPUT);
     pinMode(IN3, OUTPUT);
     pinMode(ENB, OUTPUT);
}

void loop() {
 //Serial.write(BTserial.read()); // w przypadku testu komunikacji BT, wypisywanie odebranych znaków przez BT na monitor szeregowy
  if(BTserial.read()=='W') 
  { // jazda do przodu
    //różnica w ustawionych parametrach wynika z tego, że finalna konstrukcja robota nie poruszała sie w linii prostej 
    // i dokonywano korekcji poprzez zmiany szybkości obrotu wałków silników 
  Motor1_Forward(200);
  Motor2_Forward(162);  
  }
  else if(BTserial.read()=='S')
  {
  Motor1_Backward(200);
  Motor2_Backward(162);  
  }
 else if(BTserial.read()=='A')
  {
  //obrót w lewo
  Motor1_Backward(200);
  Motor2_Forward(200);  
  }
  else if(BTserial.read()=='D')
  {
  //obrót w prawo
  Motor1_Forward(200);
  Motor2_Backward(200);  
  }
}

void Motor1_Forward(int Speed)
{
     digitalWrite(IN1,HIGH);
     digitalWrite(IN2,LOW);
     analogWrite(ENA,Speed);
}

void Motor1_Backward(int Speed)
{
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
     analogWrite(ENA,Speed);
}
void Motor1_Brake()
{
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,LOW);
}
void Motor2_Forward(int Speed)
{
     digitalWrite(IN3,HIGH);
     digitalWrite(IN4,LOW);
     analogWrite(ENB,Speed);
}

void Motor2_Backward(int Speed)
{
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,HIGH);
     analogWrite(ENB,Speed);
}
void Motor2_Brake()
{
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,LOW);
}
