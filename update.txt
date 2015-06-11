So I have decided to start playing with OKLT20 chipsets as they seem to be more versatile in the resistance they require to produce output and can be juiced up to 6v just like the raptor without causing damage to the chipset as they still provide 20a output
What does this mean for us? 
Well:
I have found 2.5k ohm Digital Pot's that can be used in tandem with a 500ohm SMD resistor to give us a total variable output of 3k ohms.
That means we can wipe from 3.14ish volt out all the way up to 6v out @ 20a with complete control over a digital potentiometer.
The digipot I have located has a resolution of 256 steps. 
That gives 9.76 ohm per step resolution. This device is controlled via I2C
I intend to control the screen over i2c (unless arduino wont support multiple device addressing in which case I will shoot for SPI)  and the digipot over i2c
This device is intented to have coil resistance reading
and customizable wattage input/output as well as sleep modes
In theory this chip could run 120w max with a minimum of a .3 ohm coil load

Downsides:
If you use over a .3 ohm coil your maximum wattage output will realistically only go up to about 1.5 ohm
which IMO is sufficient for todays vapors of all kinds. 0-120w with .3-1.5ohm support

Todo:
Determine a smart way to do temperature control and impliment the functionality at a later point
add a clock (everyone loves clocks)




Parts to be used:
AD5173BRMZ2.5
Data Sheet:
http://www.farnell.com/datasheets/1789172.pdf
Link to buy:
http://uk.farnell.com/analog-devices/ad5173brmz2-5/digital-pot-2-5kohm-dual-msop/dp/2461289

OKL2-T/20-W12
Data Sheet:
http://power.murata.com/data/power/okl2-t20-w12.pdf
Link to buy:
http://www.digikey.com/product-detail/en/OKL2-T%2F20-W12N2-C/811-2961-1-ND/4738836

Arduino Pro Mini (Atmega 328pau)
Data Sheet:
http://www.arduino.cc/en/Main/ArduinoBoardProMini
Link to buy:
http://www.amazon.com/gp/product/B00L62KAWO/ref=pd_lpo_sbs_dp_ss_3?pf_rd_p=1944687502&pf_rd_s=lpo-top-stripe-1&pf_rd_t=201&pf_rd_i=B004G53J5I&pf_rd_m=ATVPDKIKX0DER&pf_rd_r=1GRYSVT9H9YSP6R7QXQ5

sspd1306 128x32 OLED display:
Data Sheet:
http://www.adafruit.com/datasheets/SSD1306.pdf
http://www.adafruit.com/datasheets/UG-2832HSWEG02.pdf
Link to buy:
https://www.adafruit.com/products/931


