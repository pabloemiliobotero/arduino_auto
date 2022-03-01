

#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd (0x27, 16, 2);// si no te sale con esta direccion  puedes usar (0x3f,16,2)||(0x20,16,2)
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //    ( RS, EN, d4, d5, d6, d7)
//#include "Sodaq_DS3231.h"
#include "RTClib.h" 
RTC_DS3231 RTC; // creamos el objeto RTC
char DiaSemana[][4] = {"Dom", "Lun", "Mar", "Mie", "Jue", "Vie", "Sab"};
    // La linea fija la fecha, hora y dia de la semana, se debe suprimir la linea en la segunda carga
    // Ejemplo 2018 noviembre 11, 08:00:00  dia 6-Sabado (0=Dom, 1=Lun, 2=Mar, 3=Mie, 4=Jue, 5=Vie, 6=Sab)
    // DateTime dt(2018, 11, 14, 22, 12, 0, 3);

void setup() {
  
 pinMode(2,OUTPUT);
 
 RTC.begin(); 
 Wire.begin();
 Serial.begin(9600);
 lcd.begin(20, 4); // Fijar el numero de caracteres y de filas
 print_time();
// lcd.print("PRUEBA PANTALLA LCD PARA UN INTERRUPTOR"); // Enviar el mensaje
// lcd.init();
// lcd.backlight();
// lcd.setCursor (0,0);
// lcd.print ("carlos");
// delay(2000);
// lcd.clear();
//   // La linea fija la fecha, hora y dia de la semana, se debe suprimir la linea en la segunda carga 
//   // rtc.setDateTime(dt);
}

void loop() {
  DateTime ahora = RTC.now();
//   DateTime ahora = RTC.now(); // captura valores del tiempo
    lcd.setCursor(0,0);
    lcd.print(DiaSemana[ahora.dayOfTheWeek()]);
    lcd.print(' ');
    lcd.print(ahora.day(), DEC);
    lcd.print('/');
    lcd.print(ahora.month(), DEC);
    lcd.print('/');
    lcd.print(ahora.year(), DEC);
    lcd.print('/');
    lcd.setCursor(4,1);
    lcd.print(ahora.hour(), DEC);
    lcd.print(':');
    lcd.print(ahora.minute(), DEC);
    lcd.print(':');
    lcd.print(ahora.second(), DEC); 
   delay(1000);
   lcd.clear();
int hora    =ahora.hour();
int minuto  =ahora.minute();
int segundo =ahora.second();
//   if(hora >=23 ){
   if(hora >=5 && hora <16 ){ 
   digitalWrite(2,true);
//   lcd.setCursor(0,4);
//   lcd.print("LUZ ENCENDIDA");
//   Serial.print("LUZ ENCENDIDA");
     Serial.print(ahora.hour(), DEC);
     Serial.print(':');
     Serial.print(ahora.minute(), DEC);
     Serial.print(':');
     Serial.print(ahora.second(), DEC);
     Serial.print('-');
   }
   
   else {
   digitalWrite(2,false);
//     lcd.setCursor(0,4);
//   lcd.print("LUZ APAGADA");
     Serial.print("LUZ APAGADA");
     Serial.print(ahora.hour(), DEC);
     Serial.print(':');
     Serial.print(ahora.minute(), DEC);
     Serial.print(':');
     Serial.print(ahora.second(), DEC);
     Serial.print('-');
   }
}

void print_time() {
// lcd.setCursor(0,0);
 DateTime ahora = RTC.now(); // captura valores del tiempo
 Serial.print(ahora.day(), DEC);
 Serial.print('/');
 Serial.print(ahora.month(), DEC);
 Serial.print('/');
 Serial.print(ahora.year(), DEC);

 Serial.print(" (");
 Serial.print(DiaSemana[ahora.dayOfTheWeek()]);
 Serial.print(") ");

 if (ahora.hour() <10) Serial.print (0); 
 Serial.print(ahora.hour(), DEC);
 Serial.print(':');

 if (ahora.minute() <10) Serial.print (0); 
 Serial.print(ahora.minute(), DEC);
 Serial.print(':');

 if (ahora.second() <10) Serial.print (0); 
 Serial.print(ahora.second(), DEC);
 Serial.println();
}
