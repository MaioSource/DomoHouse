/*
┏━━━┓╋╋╋╋╋╋╋╋┏┓╋┏┓
┗┓┏┓┃╋╋╋╋╋╋╋╋┃┃╋┃┃
╋┃┃┃┣━━┳┓┏┳━━┫┗━┛┣━━┳┓┏┳━━┳━━┓
╋┃┃┃┃┏┓┃┗┛┃┏┓┃┏━┓┃┏┓┃┃┃┃━━┫┃━┫
┏┛┗┛┃┗┛┃┃┃┃┗┛┃┃╋┃┃┗┛┃┗┛┣━━┃┃━┫
┗━━━┻━━┻┻┻┻━━┻┛╋┗┻━━┻━━┻━━┻━━┛

DomoHouse is an easy-implementation module to control your house from internet through an app in your smartphone or tablet. 
It consist in a client-server conection and it is all based on arduino platform. 

www.DomoHouse.esy.es

Arduino file!

Arduino UNO
Ethernet shield
Luz habitacion = pin 2
Luz cocina = pin 3
Luz living = pin 4
Luz baño = pin 5
Luz habitacion sec = pin 6
Luz comedor = pin 7
Sensor baño = pin 8
Sensor humedad y temperatura = pin 9
Luz corredor = pin 15
puente h = IN1(pin 14) IN2(pin 19)

Enjoy it!

*/

#include <SPI.h>
#include <Ethernet.h>
#include <DHT11.h>


String readString;

//Definimos una MAC y una IP para el arduino
byte mac[] = { 0xDE,0xAD,0xBE,0xFF,0xFE,0xED };
byte ip[] = { 192, 168, 0, 50 };
byte gateway[] = { 192, 168, 0, 1 };                  
byte subnet[] = { 255, 255, 255, 0 }; 

DHT11 dht11(9);

//Habitacion Principal
int luzHabitacion = 2;
int estadoLuzHabitacion = 0;
//Habitacion secundaria
int luzHabitacionSec = 6;
int estadoLuzHabitacionSec = 0;
//Cocina
int luzCocina = 3;
int estadoLuzCocina = 0;
//Comedor
int luzComedor = 7;
int estadoLuzComedor = 0;
//Living
int luzLiving = 4;
int estadoLuzLiving = 0;
//Baño
const int sensorTocador = 8;
const int luzTocador = 5;
int estadoSensorTocador = 0;
//Garage
int puertaAbrir = 14;
int puertaCerrar = 19;
int estadoGarage = 0;
//Corredor
int luzCorredor = 15;
int estadoLuzCorredor = 0;
//Alarma
int estadoAlarma = 0;
EthernetServer server(80);

void setup() {
  pinMode(luzHabitacion, OUTPUT);
  pinMode(luzHabitacionSec, OUTPUT);
  pinMode(luzTocador, OUTPUT);
  pinMode(sensorTocador, INPUT);
  pinMode(luzCocina, OUTPUT);
  pinMode(luzLiving, OUTPUT);
  pinMode(luzComedor, OUTPUT);
  pinMode(puertaAbrir, OUTPUT);
  pinMode(puertaCerrar, OUTPUT);
  pinMode(luzCorredor, OUTPUT);
  Serial.begin(9600);
  //Iniciamos el servidor
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  
}

void loop() {

  ethernet();
  habitacion();
  cocina();
  living(); 
  tocador();
  habitacionSec();
  comedor();
  corredor();  
}

//Hacemos conexion con el servidor
void ethernet ()
{

//float temperatura = T();
//int humedad = H();
 // Serial.println(humedad);
 // Serial.println(temperatura);


  EthernetClient client = server.available();

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  
          client.println("Refresh: 1");  
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<center>");
          client.print("20");
          client.println("C");
          client.print("41");
          client.println("%");
          client.println("</center>");
          client.println("</html>");
  if (client) 
  {
  
    boolean newLine = true;
    String line = "";
    while (client.connected() && client.available()) 
    {
      char c = client.read();
      
        if (c == '\n')
        {
          newLine = true;
          programa(line);
          line = "";
        } 
        else if (c != '\r') 
        {
          newLine = false;
          line += c; 
        }

    }
    programa(line);
    delay(1);
    client.stop();   
  }
}

//Hacemos conexion con la app 
void programa(String line)
{  
  if (line.startsWith("tag", 0)) {
    String android = line.substring(4, line.length());
//////////////////////HABITACION////////////////////////////////
//////////////////////HABITACION////////////////////////////////
//////////////////////HABITACION////////////////////////////////
    if (android == "A") 
      estadoLuzHabitacion = 1;
    if (android == "B") 
      estadoLuzHabitacion = 0;
//////////////////////VENTANA/////////////////////////////////////
    if (android == "C") 
      estadoAlarma = 0;
    if (android == "D") 
      estadoAlarma = 1;
//////////////////////COCINA////////////////////////////////////
//////////////////////COCINA////////////////////////////////////
//////////////////////COCINA////////////////////////////////////
    if (android == "E") 
      estadoLuzCocina = 1;
    if (android == "F") 
      estadoLuzCocina = 0;
//////////////////////COMEDOR///////////////////////////////////
//////////////////////COMEDOR///////////////////////////////////
//////////////////////COMEDOR///////////////////////////////////
    if (android == "K") 
      estadoLuzComedor = 1;
    if (android == "L") 
      estadoLuzComedor = 0;
//////////////////////LIVING////////////////////////////////////
//////////////////////LIVING////////////////////////////////////
//////////////////////LIVING////////////////////////////////////
    if (android == "G") 
      estadoLuzLiving = 1;
    if (android == "H") 
      estadoLuzLiving = 0;
//////////////////////HABITACION2////////////////////////////////
//////////////////////HABITACION2////////////////////////////////
//////////////////////HABITACION2////////////////////////////////
    if (android == "I") 
      estadoLuzHabitacionSec = 1;
    if (android == "J") 
      estadoLuzHabitacionSec = 0;
//////////////////////Garage//////////////////////////////////////
//////////////////////Garage//////////////////////////////////////
//////////////////////Garage//////////////////////////////////////
    if (android == "M") 
      {
        digitalWrite(puertaAbrir, 1);
        digitalWrite(puertaCerrar,0); 
        delay(1000);
        digitalWrite(puertaAbrir, 0);
        digitalWrite(puertaCerrar,0);
        digitalWrite(16, HIGH);
      }
    if (android == "N")
    {
        digitalWrite(puertaCerrar,1);
        digitalWrite(puertaAbrir,0);
        delay(1000);
        digitalWrite(puertaAbrir, 0);
        digitalWrite(puertaCerrar,0);
        digitalWrite(16, LOW);
    }
//////////////////////Corredor////////////////////////////////////
//////////////////////Corredor////////////////////////////////////
//////////////////////Corredor////////////////////////////////////
      if (android == "O") 
        estadoLuzCorredor = 0;
      if (android == "P") 
        estadoLuzCorredor = 1;
//////////////////////ALARMA//////////////////////////////////////
//////////////////////ALARMA//////////////////////////////////////
//////////////////////ALARMA//////////////////////////////////////
//      if (android == "S")
//      {
//        estadoAlarma = 1;
//        Serial.print(estadoAlarma);
//        estado=Serial.read();
//        if(estado==0){
//          analogWrite(alarma,138);
//        }
//        
//      }
//      if (android == "T")
//      {
//        estadoAlarma = 0;
//        Serial.print(estadoAlarma);
//      }
      
      
 }
}

//Control de la habitacion
void habitacion()
{
  if (estadoLuzHabitacion == 1)
  {
  digitalWrite(luzHabitacion, HIGH);
  }
  if (estadoLuzHabitacion == 0)
  {
  digitalWrite(luzHabitacion, LOW);   
  }
}  

//Control de la habitacion Secundaria
void habitacionSec()
{
  if (estadoLuzHabitacionSec == 1)
  {
  digitalWrite(luzHabitacionSec, HIGH);
  }
  if (estadoLuzHabitacionSec == 0)
  {
  digitalWrite(luzHabitacionSec, LOW);   
  }
}
//Control de la cocina
void cocina()
{
  if (estadoLuzCocina == 1)
  {
  digitalWrite(luzCocina, HIGH);
  }
  if (estadoLuzCocina == 0)
  {
  digitalWrite(luzCocina, LOW);   
  }
}
//Control del comedor
void comedor()
{
  if (estadoLuzComedor == 1)
  {
  digitalWrite(luzComedor, HIGH);
  }
  if (estadoLuzComedor == 0)
  {
  digitalWrite(luzComedor, LOW);   
  }
}

//Control del living
void living()
{
  if (estadoLuzLiving == 1)
  {
  digitalWrite(luzLiving, HIGH);
  }
  if (estadoLuzLiving == 0)
  {
  digitalWrite(luzLiving, LOW);   
  }
}

//Luz Baño
void tocador()
{
  estadoSensorTocador = digitalRead(sensorTocador);
  if(estadoSensorTocador == 1)
  {
    digitalWrite(luzTocador, HIGH);
    
  }
  else
  {
    digitalWrite(luzTocador, LOW);
  }
    
}
int T()
{
  int estadoT=0;
  float temp, hum;
  if((estadoT = dht11.read(hum, temp)) == 0)   
          {
          //   Serial.print(temp);
         //     Serial.println(" C");
         //    Serial.print(hum);
         //   Serial.println(" %");
          }
         
    
       return temp;
}
int H()
{
  int estadoH;
  float temp, hum;
  if((estadoH = dht11.read(hum, temp)) == 0)   
          {
          //   Serial.print(temp);
         //    Serial.println(" C");
         //    Serial.print(hum);
         //    Serial.println(" %");
          }
         
    
       return hum;
}

//void garage() 
//{
//
//  digitalWrite(puertaAbrir, LOW);
//  digitalWrite(puertaCerrar, HIGH);
//  delay(1000);
//  digitalWrite(puertaAbrir, LOW);
//  digitalWrite(puertaCerrar, LOW);
//  loop();
//}
//void garageCerrar() 
//{
//
//  digitalWrite(puertaAbrir, LOW);
//  digitalWrite(puertaCerrar, HIGH);
//  delay(1000);
//  digitalWrite(puertaAbrir, LOW);
//  digitalWrite(puertaCerrar, LOW);
//  loop();
//
//}

void corredor()
{
  if (estadoLuzCorredor == 1)
  {
  digitalWrite(luzCorredor, HIGH);
  }
  if (estadoLuzCorredor == 0)
  {
  digitalWrite(luzCorredor, LOW);   
  }
}
