#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


RF24 radio(9, 10); //Establezco los pines de CE y CS  
const uint64_t pipe = { 0xF0F0F0F0E1LL}; //Pipe de comunicacion a usar. Puede ser cualquier cadena de 40-bits hexa. Tiene que ser la misma que la del receptor
const String miHabitacion = "HABI1";
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe); //Numero de pipe a abrir, pipe
  radio.startListening(); //Comienza a escuchar

}

void accionar(String accion){
  if(accion == "LuzOnn"){
    digitalWrite(2, 1);
  }
  else if(accion == "LuzOff"){
    digitalWrite(2, 0);
  }
}

void procesador(char mensaje[]){
  String accion="";
  for(int i=0;i<6;i++){
    accion+=mensaje[i];
  }
  String habitacion="";
  for(int i=7;i<12;i++){
    habitacion+=mensaje[i];
  }

  if(habitacion == miHabitacion){
    accionar(accion);
  }
}

void loop()
{
  int largoMensaje = 13;
  char mensaje[largoMensaje];
  if ( radio.available() )
  {
    radio.read(mensaje, largoMensaje);
    Serial.println(mensaje);
    delay(100);
  }
  procesador(mensaje);
}



