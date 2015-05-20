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
const int voltPin = 0; 
int mVperAmp = 66; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double Amps = 0;
int ohmPin= 1;
int raw= 0;
int Vin= Voltage;
float Vout= 0;
float R1= 5;
float R2= 0;
float buffer= 0;

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
}


void loop(){
display.setTextColor(WHITE);
display.setTextSize(4);
display.setCursor(1,0);
display.print("V:");
display.setCursor(1,3);
checkvoltamp;
display.print(Voltage,3);
display.setCursor(5,0);
display.print("Amps:");
display.setCursor(5,6);
display.print(Amps,3);
checkohm;
display.setCursor(1,5);
display.print("ohm:");
display.setCursor(1,11);
display.print(R2,3);


}

//Declare this as a universal call out instead of running in loop that way we can just call to the function from the loop
//todo: move this to its own CPP and h file
static void checkvoltamp()
  {
  RawValue = analogRead(voltPin);
  Voltage = (RawValue / 1023.0) * 5000; // Gets you mV
  Amps = ((Voltage - ACSoffset) / mVperAmp);
}
  
static void checkohm()
{
  raw= analogRead(ohmPin);
if(raw) 
  {
  buffer= raw * Vin;
  Vout= (buffer)/1024.0;
  buffer= (Vin/Vout) -1;
  R2= R1 * buffer;
  }
}
