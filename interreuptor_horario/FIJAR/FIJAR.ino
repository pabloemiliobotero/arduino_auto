int ano = 2020; // 0-2099
int mes = 9; // 0-12
int dia = 18; // 0-31
int hora= 12; // 0-23
int mins = 53; // 0-59
int seg = 0; // 0-59
// ===========================
 
#include <Wire.h> // Comunicacion I2C 
#include "RTClib.h" // libreria ADAFRUIT para DS3231 
 
 
RTC_DS3231 RTC; // creamos el objeto RTC
String dia_semana[]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
String newdate = "";
void setup() { 
  Serial.begin(9600);
  newdate = "Fecha Nueva-> "
  + String(dia) + "/"
  + String(mes) + "/"
  + String(ano) + " Hora-> "
  + String(hora)+ ":"
  + String(mins) + ":"
  + String(seg);
  RTC.adjust(DateTime(ano, mes, dia, hora, mins, seg));
 
  Serial.println(newdate); 
}

void loop () {
  
}
  
