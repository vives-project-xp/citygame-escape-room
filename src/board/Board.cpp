#include "Board.h"
#include "Lcd.h"

Serial gps_serial(PTC17,PTC16);
I2C i2c(PTE25, PTE24);

Board::Board(Log::LoggerInterface * logger){
   gps = new Gps(&gps_serial, logger);
   leds = new Leds(&i2c);
   lcd = new Lcd();
   keys = new Keys();

   leds->setStartState();
   lcd->setStartScreen();
   
}
