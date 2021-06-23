#include <string.h>
#include "COLOR.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Creo el LCD 16x2
LiquidCrystal_I2C lcd(0x27,16,2);
// Declaro el botón, su pin y estado
const int buttonPin = 2;
int buttonState = 0;
  
// Inicializo el monitor serial, el boton como input, el display 16x2 y escribo primeras instrucciones, inicializo el sensor.
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Iniciando");
  lcd.setCursor(0, 1);
  lcd.print("Clasificador 404");
  delay(2500);
  lcd.clear();
  lcd.print("Clasificador 404");
  lcd.setCursor(0, 1);
  lcd.print("Equipo 1 - TI3");
  delay(2500);
  lcd.clear();
  lcd.print("Para clasificar");
  lcd.setCursor(0, 1);
  lcd.print("Pulse el boton");
  COLOR_init();
  Serial.println("Empezando lectura del sensor");
}

// Leo el estado del botón, cuando el boton está en HIGH comienzo lectura del sensor.
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    lcd.clear();
    Serial.println (COLOR_getColorName()); // Se obtiene el nombre del color que esté viendo el sensor y se imprime en el monitor (Herramientas > Monitor Serial)
    lcd.print(COLOR_getColorName());
    delay(2000); // Dejar un pequeño tiempo entre cada ciclo es bueno para que el Arduino no corra como loco. Si tienen un programa un poco más inteligente, no es necesario.
    lcd.clear();
    lcd.print("Para clasificar");
    lcd.setCursor(0, 1);
    lcd.print("Pulse el boton");
  }
  else
  {
  }
}
