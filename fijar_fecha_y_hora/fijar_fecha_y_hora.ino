 
// valores a introducir para configurar el RTC
// ===========================
int ano = 2020; // 0-2099
int mes = 9; // 0-12
int dia = 22; // 0-31
int hora= 6; // 0-23
int mins = 44; // 0-59
int seg = 0; // 0-59
// ===========================
 
#include <Wire.h> // Comunicacion I2C 
#include "RTClib.h" // libreria ADAFRUIT para DS3231 
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //    ( RS, EN, d4, d5, d6, d7)

 
RTC_DS3231 RTC; // creamos el objeto RTC
 
String dia_semana[]={"Dominsgo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
String newdate = "";
 
 
void setup() { 
  lcd.begin(20, 4); // Fijar el numero de caracteres y de filas
 // RTC.adjust(DateTime(ano, mes, dia, hora, mins, seg));
  Serial.begin(9600);
// Wire.begin(); // Inicia Wire sólo si no se hace dentro de la librería 
// supone que se usa Wire para comunicar con otros dispositivos, no sólo con el DS3231
 
 if (!RTC.begin()) {
 
 Serial.println("No se encuentra RTC");
 while (1);
 
 }else{
 
 Serial.println("########################################"); 
 Serial.println("Puesta en hora del modulo RTC DS3231");
 Serial.print("Fecha actual: ");
 print_time(); // imprime hora actual del RTC
 Serial.println("########################################"); 
 Serial.println(""); 
 Serial.println("Pulsa ENTER para actualizar a"); 
 newdate = "Fecha Nueva-> "
 + String(dia) + "/"
 + String(mes) + "/"
 + String(ano) + " Hora-> "
 + String(hora)+ ":"
 + String(mins) + ":"
 + String(seg);
 Serial.println(newdate);
 
 Serial.println("======================================"); 
 if(Serial.available()) {
 int inputByte = Serial.read(); // lee byte entrante
 
 if (inputByte==13) { // caracter fin de linea
 RTC.adjust(DateTime(ano, mes, dia, hora, mins, seg));
 Serial.print("Nueva Fecha actualizada: ");
 print_time(); // imprime hora actual del RTC 
 }
 }
 }
}
 
void loop () {
 

}
 
void print_time() {
 lcd.setCursor(0,0);
 DateTime ahora = RTC.now(); // captura valores del tiempo
 Serial.print(ahora.day(), DEC);
 Serial.print('/');
 Serial.print(ahora.month(), DEC);
 Serial.print('/');
 Serial.print(ahora.year(), DEC);
// pantalla
 lcd.print(ahora.day(), DEC);
 lcd.print('/');
 lcd.print(ahora.month(), DEC);
 lcd.print('/');
 lcd.print(ahora.year(), DEC);
 
 Serial.print(" (");
 Serial.print(dia_semana[ahora.dayOfTheWeek()]);
 Serial.print(") ");
// pantalla
 lcd.print(" (");
 lcd.print(dia_semana[ahora.dayOfTheWeek()]);
 lcd.print(") ");
 
 if (ahora.hour() <10) Serial.print (0); 
 Serial.print(ahora.hour(), DEC);
 Serial.print(':');
 // pantalla
 lcd.print(ahora.hour(), DEC); // pantalla
 lcd.print(':');// pantalla
 
 if (ahora.minute() <10) Serial.print (0); 
 Serial.print(ahora.minute(), DEC);
 Serial.print(':');
 // pantalla
 lcd.print(ahora.minute(), DEC);
 lcd.print(':');
 
 if (ahora.second() <10) Serial.print (0); 
 Serial.print(ahora.second(), DEC);
 Serial.println();
 // pantalla
 lcd.print(ahora.second(), DEC);
// lcd.println();
 
}
