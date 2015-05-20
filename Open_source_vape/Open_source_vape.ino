/*
GNU GPLv3 License

Contributor list:
Zarboz
*/
//list libraries needed here
#include <Arduino.h>
#include <avr/sleep.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

//declare global vars here
const int voltPin = 0;  //output voltage between dividers goes into analog pin 0 using 10kohm resistor and 2.5k ohm resistor we will have accuracy to the hundredth up to 25v.
int voltres1 = 10000;
int voltres2 = 2500;
float denominator;
float voltage;

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    14
#define OLED_CS    15
#define OLED_RESET 16
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup () { 
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display(); // show splashscreen
  delay(500);
  display.clearDisplay();
  denominator = (float)voltres2 / (voltres1 + voltres2);
}


void loop(){
display.setTextColor(WHITE);
display.setTextSize(4);
display.print("V:");
checkvolt;
display.print(voltage);
}

//Declare this as a universal call out instead of running in loop that way we can just call to the function from the loop
//todo: move this to its own CPP and h file
static void checkvolt(	
	voltage = analogRead(voltPin);
	voltage = (voltage / 1024) * 5.0;
	voltage = voltage / denominator;
	delay (500);
	}
