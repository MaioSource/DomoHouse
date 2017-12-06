#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9, 10); //Establezco los pines de CE y CS
const uint64_t pipe = { 0xF0F0F0F0E1LL}; //Pipe de comunicacion a usar. Puede ser cualquier cadena de 40-bits hexa. Tiene que ser la misma que la del receptor


void setup(){
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.setRetries(15, 15); //Si falla el envio, lo vuelve a mandar en <delay, contador> (Cuanto espera, cuantos intentos)
  //radio.setPayloadSize(8); //Cambia el tamaño maximo de los datos a enviar (Por defecto 32 bytes)
  radio.openWritingPipe(pipe); //Abre el pipe de comunicacion
  radio.setPALevel(RF24_PA_MAX); 
}

String mensaje="";

void loop() {
  if(Serial.available()){
  char estado = Serial.read();
  mensaje+=estado;
  if (estado == '/'){
     enviar();
  }
 }
}

void enviar(){
  Serial.println(mensaje);
  int largoMensaje = 13;
  char msj[largoMensaje] = "";
  mensaje.toCharArray(msj, largoMensaje);
  radio.write(msj, largoMensaje);
  delay(100);
  mensaje="";

}
