/*
GNU GPLv3 License

Contributor list:
Zarboz
Claviger battery code
*/
//list libraries needed here
#include <Arduino.h>
#include <avr/sleep.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

//declare global vars here
//pinout goes here
const int voltPin = A0; //acs712 input to A0 
const int ohmPin= A1; //voltage divider with our 5ohm resistor
const int batteryVoltage = A2; //readout our battery voltage with a2 with 4.7k ohm voltage divider being read.

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    14
#define OLED_CS    15
#define OLED_RESET 16

//vars go here
int mVperAmp = 66; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double Amps = 0;
int raw= 0;
int Vin= Voltage;
float Vout= 0;
float R1= 5;  //we use a 5ohm resistor for the ohmpinA1 voltage divider in order to determine our atomizer resistance
float ohm= 0;
float buffer= 0;
float watt= 0;
float Bvoltage2 = 0;
int Bpercent = 0; 
float Vbatt = 0;


Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup () { 
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display(); // show splashscreen
  delay(500);
  display.clearDisplay();
}


void loop(){
 //First things first lets check our battery and make sure we are able to run if battery is low then display a lockout screen
checkbatt;
if (Bvoltage2 < 6.39) 
  {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(22,9);
    display.print("LOW BATTERY");
    display.setCursor(16,34);
    display.print("Please Charge");
    display.setCursor(40,51);
    display.print("BV:");
    display.print(Bvoltage2);
    display.ssd1306_command(SSD1306_DISPLAYOFF);
  }
  else{
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
display.print(ohm,3);
checkwatt;
display.setCursor(5,7);
display.print("W:");
display.setCursor(5,10);
display.print(watt);
  }

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
  ohm= R1 * buffer;
  }
}

static void checkwatt()
{
  watt = (sq(Voltage) / ohm);
  delay(10);
}

static void checkbatt()
{
  Vbatt = analogRead(batteryVoltage);               // Reads the voltage of analog pin 2 to determin the voltage going to the battery
  float Bvoltage1 = Vbatt * (5.0 / 1023);      // Convert the raw value being read from analog pin 1 into a voltage value
  float Bvoltage2 = 2 * Bvoltage1;             //doubles the initial battery voltage calculation, required because the battery voltage is read using a voltage divider so is 1/2 what it really is, needed for safety of arduino since it will be over 5 volts
  float Bpercent1 = (Bvoltage2 - 6.4);         // creats a value to use in calculating battery percetn remaining.
  int Bpercent = (Bpercent1 * 100) / 2; 
}
