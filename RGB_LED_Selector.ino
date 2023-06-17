/*
  RGB_LED_Selector.ino

  Author: Vincent Langlois
  Created: 6/16/2023
  Last Modified: 6/17/2023

  Description: This Arduino sketch controls an RGB LED using three potentiometers. 
  The RGB LED's color is determined by the values read from the potentiometers, 
  with each potentiometer representing one of the primary colors: Red, Green, and Blue.

  Hardware Requirements:
  - Arduino UNO
  - RGB LED
  - Breadboard
  - Three potentiometers
  - Three 100 μF capacitors
  - Three 220 Ω resistors
  - Jumper wires

  This code is part of the RGB LED Selector project.

  MIT License
*/

struct Color
{
  const int ledPin; // the color's RGB LED PWD pin output
  const int potPin; // the color's potentiometer analog pin input
  int colorValue;   // the value of the color, from 0 to 255
  int potValue;     // the value of the potentiometer, from 0 to 1023
};

// RGB colors
Color red = {9, A2, 0, 0};
Color green = {11, A1, 0, 0};
Color blue = {10, A0, 0, 0};

// potentiometer constants
const int MIN_POT_VAL = 0;
const int MAX_POT_VAL = 1023;
// RGB color constants
const int MIN_COLOR = 0;
const int MAX_COLOR = 255;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  // set each color led pins to output
  pinMode(red.ledPin, OUTPUT);
  pinMode(green.ledPin, OUTPUT);
  pinMode(blue.ledPin, OUTPUT);
}

void loop()
{
  // Read potentiomotor value
  red.potValue = analogRead(red.potPin);
  blue.potValue = analogRead(blue.potPin);
  green.potValue = analogRead(green.potPin);

  Serial.print("Potentiometer Values: \t Red: ");
  Serial.print(red.potValue);
  Serial.print("\t Green: ");
  Serial.print(blue.potValue);
  Serial.print("\t Blue: ");
  Serial.println(blue.potValue);

  // convert to RGB color
  red.colorValue = map(red.potValue, MIN_POT_VAL, MAX_POT_VAL, MIN_COLOR, MAX_COLOR);
  green.colorValue = map(green.potValue, MIN_POT_VAL, MAX_POT_VAL, MIN_COLOR, MAX_COLOR);
  blue.colorValue = map(blue.potValue, MIN_POT_VAL, MAX_POT_VAL, MIN_COLOR, MAX_COLOR);

  Serial.print("Color Values: \t Red: ");
  Serial.print(red.colorValue);
  Serial.print("\t Green: ");
  Serial.print(blue.colorValue);
  Serial.print("\t Blue: ");
  Serial.println(blue.colorValue);

  // color the LED based on each color's color value
  analogWrite(red.ledPin, red.colorValue);
  analogWrite(green.ledPin, green.colorValue);
  analogWrite(blue.ledPin, blue.colorValue);
}
