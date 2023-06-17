# RGB LED Selector

An interactive educational experience built to demonstrate an Arduino's analog and PWD pins for a young audience. Built for developers and educators alike.

## Description

The RGB LED Selector project utilizes an Arduino UNO board to control an RGB LED using three potentiometers. The RGB LED's color is determined by the values read from the potentiometers. Each potentiometer corresponds to one of the primary colors: Red (R), Green (G), and Blue (B).

The project components include:

- Arduino UNO
- RGB LED
- Breadboard
- Three potentiometers
- Three 100 μF capacitors
- Three 220 Ω resistors
- Jumper wires

The project is built on a breadboard, where the Arduino's 5V and ground pins are connected to the breadboard's power buses.

Each potentiometer is connected to power and ground. To smooth out voltage changes and prevent potential hazards, it is crucial to connect a 100 μF capacitor between the power bus and the potentiometer. The potentiometer's middle pin is connected to an analog input on the Arduino. 

For the RGB LED, each color pin is connected to a PWM digital pin on the Arduino. These pins output the corresponding color's value. Each of these pin's jumper wires passes through a 220 Ω resistor before connecting to the respective pin of the RGB LED. The ground pin of the RGB LED is connected directly to the ground through a jumper wire.

The code uses a data structure to represent a color, defined as follows:

```cpp
struct Color {
  const int ledPin; // the color's RGB LED PWM pin output
  const int potPin; // the color's potentiometer analog pin input
  int colorValue;   // the value of the color, ranging from 0 to 255
  int potValue;     // the value of the potentiometer, ranging from 0 to 1023
};
```

Once the pins are set up, the code continuously checks the potentiometer values, maps them to RGB color values (0-255), and sets the PWM output pins to produce the desired color.

# Instructions

To use this project, follow these steps:

1. Connect the Arduino UNO board to the breadboard, ensuring that the 5V and ground pins are connected to the power buses on the breadboard.

2. Connect each potentiometer to power and ground. **Important: Please observe the following capacitor connection instructions carefully**:

   - Connect the cathode (the side marked with a stripe or a negative sign) of each 100 μF capacitor to the ground rail on the breadboard.
   - Connect the anode (the side without a stripe) of each 100 μF capacitor to the power rail on the breadboard.
   - Double-check the connections to ensure that the capacitors are connected properly to prevent any hazards.

3. Connect the middle pin of each potentiometer to the corresponding analog input pin on the Arduino:

   - Red to A2,
   - Green to A1
   - Blue to A0

4. Connect the RGB LED to the Arduino. Connect each color pin of the RGB LED to the PWM digital pin on the Arduino:
   - Red to PWD pin 9
   - Blue to PWD pin 10
   - Green to PWD pin 11
5. Ensure that each of these pins passes through a 220 Ω resistor before connecting to the corresponding pin of the RGB LED.
6. Connect the ground pin of the RGB LED directly to the ground using a jumper wire.
7. Upload the `RGB_LED_Selector.ino` code file to the Arduino UNO using the Arduino IDE or your preferred method.
8. Observe the RGB LED and adjust the potentiometers to change the color. The RGB LED will reflect the color determined by the values read from the potentiometers.

## License

This project is licensed under the MIT License. Developers and educators are free to use this project for their own purposes. You are obligated to provide attribution in the event you use this project in your projects.

## Warning

**It is crucial to follow the capacitor connection instructions carefully to ensure safety**. Connecting the capacitors incorrectly can cause damage or pose a safety risk. If you are unsure about the proper connection, please seek assistance from someone experienced with electronics.
