#include <EEPROM.h>

#include <Wire.h>                                  // Die Datei Wire.h ist eine Programmbibliothek, um über einen I²C-Bus zu kommunizieren.
#define adresse 0x0C                               // Das Wort "adresse" bedeutet später "0x0C".
                                                   // Nebenbei: Halbe Adresse vom NXT: 24 beim Arduino entspricht 18 im Hexadezimalcode. Die Hälfte davon ist 12, also 0C beim NXT.
int einlesen;
int lese_Daten;
byte daten[9];                                     // Es handelt sich um ein Array mit 10 Bytes. Ein Byte hat Werte von 0 bis 255.

const int xpin = A1;                    // Port x-Achse
const int ypin = A2;                    // Port y-Achse
const int zpin = A3;                    // Port z-Achse
const int touchlpin = 9;
const int touchrpin = 11;
const int touchmpin = 10;
const int touchhpin = 8;
const int lslpin = A0;
const int lsrpin = A6;

int offset_x;                           // Der Offset ist ein Wert, der von den gemessenen abgezogen werden sollte, um Veränderungen besser zu sehen.
int offset_y;
int offset_z;

int x_wert;                             // x-Achsen-Werte
int y_wert;                             // y-Achsen-Werte
int z_wert;                             // z-Achsen-Werte

int lsl;
int lsr;

byte touchl;
byte touchr;
byte touchm;
byte touchh;

void Daten_erhalten(int bytesErhalten)             // Methode zum Empfangen
{
  einlesen = bytesErhalten;                        // ***
  while(1 < Wire.available())                      // *** loop through all but the last
  {                                                // ***
  }                                                // ***
  lese_Daten = Wire.read();                        // Die Daten vom NXT werden gelesen.
  //Serial.println(lese_Daten);                      // Die Daten werden am serielle Monitor angezeigt.
}

void Daten_senden()                                // Methode zum Senden
{
  if(lese_Daten == 0x00)                           // Wenn eine "0" vom NXT empfangen wurde, dann sende die Daten
  {
    daten[0] = x_wert;
    daten[1] = y_wert;
    daten[2] = z_wert;
    daten[3] = lsl;
    daten[4] = lsr;
    daten[5] = touchl;
    daten[6] = touchr;
    daten[7] = touchm;
    daten[8] = touchh;
    Wire.write(daten,9);                           // Sende die Werte über den I²C-Bus zum NXT.
  }
}

void setup()
{
  //Serial.begin(115200);                            // Die Kommunikationsadresse mit dem seriellen Monitor
  offset_x = analogRead(xpin);        // Die Offsets werden gemessen.
  offset_y = analogRead(ypin);
  offset_z = analogRead(zpin);
  Wire.begin(adresse);                             // Die Kommunikationsadresse vom NXT
  Wire.onReceive(Daten_erhalten);                  // Die Methode zum Empfangen wird gestartet und dauerhaft ausgeführt.
  Wire.onRequest(Daten_senden);                    // Die Methode zum Senden wird gestartet und dauerhaft ausgeführt.
}


void loop()
{
  x_wert = (analogRead(xpin)-offset_x) / 2 + 128;
  y_wert = (analogRead(ypin)-offset_y) / 2 + 128;
  z_wert = (analogRead(zpin)-offset_z) / 2 + 128;
  touchl = digitalRead(touchlpin);
  touchr = digitalRead(touchrpin);
  touchm = digitalRead(touchmpin);
  touchh = digitalRead(touchhpin);
  lsl = map(analogRead(lslpin), 0, 700, 0, 255);
  lsr = map(analogRead(lsrpin), 0, 700, 0, 255);
  /*Serial.print("X:");
  Serial.print(x_wert);  
  Serial.print("\t Y:");
  Serial.print(y_wert);  
  Serial.print("\t Z:");
  Serial.print(z_wert);  
  Serial.print("\t tl:");
  Serial.print(touchl);  
  Serial.print("\t tm:");
  Serial.print(touchm);  
  Serial.print("\t tr:");
  Serial.print(touchr);  
  Serial.print("\t th:");
  Serial.print(touchh);  
  Serial.print("\t lsl:");
  Serial.print(lsl);  
  Serial.print("\t lsr:");
  Serial.print(lsr);    
  Serial.println();*/
}
