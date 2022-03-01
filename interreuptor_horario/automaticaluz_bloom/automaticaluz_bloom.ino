#include <Wire.h> 
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // inicializa la interfaz I2C del LCD 16x2
RTC_DS1307 RTC;                   // inicializa el modulo RTC

const int luz = 2;
const int luz2 = 6;
const int luz3 = 7; // Pin 7 encargado de activar el luz, se conecta al Rele
int segundo;
int minuto;
int hora;
void setup () { 
  
 pinMode(luz, OUTPUT);                    // Configura como salida el pin 7
 pinMode(luz2, OUTPUT);
 pinMode(luz3, OUTPUT);
 Wire.begin();                               
 RTC.begin();                                // Inicia la comunicaci¢n con el RTC
 
 //RTC.adjust(DateTime(__DATE__, __TIME__)); // Lee la fecha y hora del PC (Solo en la primera carga)
                                             // el anterior se usa solo en la configuracion inicial luego se pone como comentario
                                             // y se vuelve a cargar el programa sin esa linea.
 Serial.begin(9600);                         // Establece la velocidad de datos del puerto serie a 9600
 lcd.init();
 lcd.backlight();                            // Coloca luz de fondo al LCD
 lcd.clear();                                // Borra el  LCD
} 
////////////////////////////////// Void loop() ///////////
void loop(){
 DateTime now = RTC.now();          // Obtiene la fecha y hora del RTC
 Serial.print(now.year(), DEC);  // A§o
 Serial.print('/');
 Serial.print(now.month(), DEC); // Mes
 Serial.print('/');
 Serial.print(now.day(), DEC);   // Dia
 Serial.print(' ');
 Serial.print(now.hour(), DEC);  // Horas
 Serial.print(':');
 Serial.print(now.minute(), DEC); // Minutos
 Serial.print(':');
 Serial.print(now.second(), DEC); // Segundos
 Serial.println();
 lcd.setCursor(0,0);
 lcd.print("D:");
 lcd.print(now.year(), DEC);
 lcd.print("/");
 lcd.print(now.month(), DEC);
 lcd.print("/");
 lcd.print(now.day(), DEC);
 lcd.print(" ");
 lcd.setCursor(0,1);
 lcd.print("T: ");
 lcd.print(now.hour(), DEC);
 lcd.print(":");
 lcd.print(now.minute(), DEC);
 lcd.print(":");
 lcd.print(now.second(), DEC);
 segundo=now.second();
 minuto=now.minute();
 hora=now.hour();

if (hora >=  6 && hora < 24) {
  digitalWrite(luz, HIGH);
  digitalWrite(luz2, LOW);
  digitalWrite(luz3, LOW);
  lcd.setCursor(0,0);
  lcd.setCursor(0,0);
  lcd.print("luz ON  ");
  Serial.println("luz Activo");
  }else{
    digitalWrite(luz, LOW);
    digitalWrite(luz2, HIGH);
    digitalWrite(luz3, HIGH);
    lcd.setCursor(0,0);
    lcd.print("luz OFF  ");
    Serial.println("Apagado");
  }
 
}
