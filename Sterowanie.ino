#include<SoftwareSerial.h>
//Realizowane z wykorzystaniem modułów BT XM-15B

SoftwareSerial BTserial(2,3); //Rx|Tx // ustwienie pinu 2,3 jako piny komunikujące się z modułem BT

//definicja pinów odpowiedzialnych za obsługę czujników
const int czujnik1 = 4;
const int czujnik2 = 5;
const int czujnik3 = 6;
const int czujnik4 = 7;
const int czujnik5 = 8;

//zdefiniowanie zmiennej przechowującej znak jaki będzie przesyłany pomiędzy modułami
//char c = ' ';

void setup() {
  //Serial.begin(9600); // monior szeregowy wykorzystywany w przypadku sprawdzania komunikacji pomiędzy płytkami 
  //arduino poprzez np. przesyłanie pojedycznych znaków

    BTserial.begin(9600); //monitor BT,inicjalizacja pracy

    //ustawienie pinów do pracy w trybie INPUT
    pinMode(czujnik1,INPUT);
    pinMode(czujnik2,INPUT);
    pinMode(czujnik3,INPUT);
    pinMode(czujnik4,INPUT);

}

void loop() {
  
  // BTserial.write(Serial.read()); // w przypadku testu komunikacji; odczytywanie znaków wpisywanych z monitora szeregowego
  // i wysyłanie ich do monitora BT
  
  //czujnik pracuje w trybie, w którym po wykryciu obiektu przed sobą ustawia stan niski
  //poniżej zdefiniowane warunki, których spełnienie skutkuje wysłaniem poszczególnego znaku odpowiadającego za 1 z 4 trybów jazdy robota; znak P odpowiada za wstrzymanie pracy robota - żaden z czujników nic nie wyrkywa
  if(~digitalRead(czujnik1))  BTserial.write('W'); // zał. jazda do przodu
  else if(~digitalRead(czujnik2))  BTserial.write('S'); //zał. jazda do tyłu
  else if(~digitalRead(czujnik3))  BTserial.write('A'); //zał. obrót w lewo
  else if(~digitalRead(czujnik4))  BTserial.write('D'); // zał. obrót w prawo
  else  BTserial.write('P'); //brak ruchu   


}
