#include <string.h>
#include "COLOR.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Creo el LCD 16x2
LiquidCrystal_I2C lcd(0x27,16,2);
  
// Todo el código que coloquen dentro de setup() se correrá una sola vez, cuando se prenda el Arduino
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Clasificador 404");
  COLOR_init();
  Serial.println("Hola Mundo!");
}

// Todo el código que coloquen dentro de loop() se corre infinitamente mientras el Arduino esté prendido, luego de haber corrido setup()
void loop() {

  Serial.println (COLOR_getColorName()); // Se obtiene el nombre del color que esté viendo el sensor y se imprime en el monitor (Herramientas > Monitor Serial)
  delay(2000); // Dejar un pequeño tiempo entre cada ciclo es bueno para que el Arduino no corra como loco. Si tienen un programa un poco más inteligente, no es necesario.
}
