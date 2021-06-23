#include <string.h>
#include "COLOR.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//Creo el LCD 16x2
LiquidCrystal_I2C lcd(0x27,16,2);
// Declaro el botón, su pin y estado
const int buttonPin = 2;
int buttonState = 0;
// Declaro Servomotor
Servo servoMotor;
// declaro contadores de tapitas
int tapitasRojas = 0;
int tapitasAzules = 0;
int tapitasVerdes = 0;
int tapitasAmarillas = 0;
int tapitasBlancas = 0;
int tapitasNegras = 0;
int tapitasGrises = 0;
int otrasTapitas = 0;


//En base al color que lee el sensor se movera el servo X grados.
//El servo se mueve en 180 grados por lo que podemos hacer 180/8 para elegir el camino (7 colores + 1 "Otros")
void moverServo (String color)
{
  //    Rojo    Azul    Verde   Amarillo    Blancos      Negro       Marrón      Otros
  //    22.5     45      67.5      90        112.5       135         157.5        180
  if (color == "ROJO" || color == "NARANJA" || color == "MARRON")
  {
    servoMotor.write(22.5);
    lcd.clear();
    tapitasRojas++;
    lcd.print("Categoria Rojo");
    lcd.setCursor(0, 1);
    lcd.print("Cantidad: " + String(tapitasRojas));
    delay(3000);
    servoMotor.write(0);
  }
  else if (color == "AZUL")
  {
    servoMotor.write(45);
    lcd.clear();
    tapitasAzules++;
    lcd.print("Categoria Azul");
    lcd.setCursor(0, 1);
    lcd.print("Cantidad: " + String(tapitasAzules));
    delay(3000);
    servoMotor.write(0);
  }
  else if (color == "VERDE")
  {
    servoMotor.write(67.5);
    lcd.clear();
    tapitasVerdes++;
    lcd.print("Categoria Verde");
    lcd.setCursor(0, 1);
    lcd.print("Cantidad: " + String(tapitasVerdes));
    delay(3000);
    servoMotor.write(0);
  }
  else if (color == "AMARILLO")
  {
    servoMotor.write(90);
    lcd.clear();
    tapitasAmarillas++;
    lcd.print("Categoria Amarillo");
    lcd.setCursor(0, 1);
    lcd.print("Cantidad: " + String(tapitasAmarillas));
    delay(3000);
    servoMotor.write(0);
  }
  else if (color == "BLANCO")
  {
    servoMotor.write(112.5);
    lcd.clear();
    tapitasBlancas++;
    lcd.print("Categoria Blanco");
    lcd.setCursor(0, 1);
    lcd.print("Cantidad: " + String(tapitasBlancas));
    delay(3000);
    servoMotor.write(0);
  }
  else if (color == "NEGRO")
  {
    servoMotor.write(135);
    lcd.clear();
    tapitasNegras++;
    lcd.print("Categoria Negro");
    lcd.setCursor(0, 1);
    lcd.print("Cantidad: " + String(tapitasNegras));
    delay(3000);
    servoMotor.write(0);
  }
  else if (color == "GRIS")
  {
    servoMotor.write(45);
    lcd.clear();
    tapitasGrises++;
    lcd.print("Categoria Grises");
    lcd.setCursor(0, 1);
    lcd.print("Cantidad: " + String(tapitasGrises));
    delay(3000);
    servoMotor.write(0);
  }
  else
  {
    servoMotor.write(180);
    lcd.clear();
    otrasTapitas++;
    lcd.print("Color desconocido");
    lcd.setCursor(0, 1);
    lcd.print("Cantidad " + String(otrasTapitas));
    delay(3000);
    servoMotor.write(0);
  }
  
}
// Inicializo el monitor serial, el boton como input,el servomotor, el display 16x2 y escribo primeras instrucciones, inicializo el sensor.
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  servoMotor.attach(3); //Asignamos el pin 3 al servomotor
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
    moverServo(COLOR_getColorName());
    delay(1000); // Dejar un pequeño tiempo entre cada ciclo es bueno para que el Arduino no corra como loco. Si tienen un programa un poco más inteligente, no es necesario.
    lcd.clear();
    lcd.print("Para clasificar");
    lcd.setCursor(0, 1);
    lcd.print("Pulse el boton");
  }
  else
  {
  }
}
