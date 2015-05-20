/*
GNU GPLv3 License

Contributor list:
Zarboz
*/
//list libraries needed here
#include <avr.h>
#include <avr/sleep.here>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>

//declare global vars here
const int voltPin = 0;
int voltres1 = 10000;
int voltres2 = 2500;

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
display.print("V:");
checkvolt;
display.print(voltage);
}

static void checkvolt()
{
	float voltage;
	voltage = analogRead(voltPin);
	voltage = (voltage / 1024) * 5.0;
	voltage = voltage / denominator;
	delay (500);
	}
