#include "Board.h"
#include "Lcd.h"

Serial gps_serial(PTC17,PTC16);
I2C i2c(PTE25, PTE24);

Board::Board(){
   gps = new Gps(&gps_serial); 
   leds = new Leds(&i2c);
   lcd = new Lcd();
   
   //----------------- TESTZONE ---------------
   
   leds->setGlobalBrightness(0.2);
   leds->setLed(0,1,0,0);    
   leds->setLed(1,0,1,0);    
   leds->setLed(2,0,0,1);    
   leds->setLed(3,1,1,0);    
   leds->setLed(4,0,1,1);    
}