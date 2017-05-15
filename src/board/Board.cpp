#include "Board.h"
#include "Lcd.h"
#include "Display.h"

Serial gps_serial(PTC17,PTC16);
I2C i2c(PTE25, PTE24);

Board::Board(Log::LoggerInterface * logger){
   gps = new Gps(&gps_serial, logger);
   leds = new Leds(&i2c);
   lcd = new Display();
   keys = new Keys();
   buzzer = new Buzzer();
   numberPad = new NumberPad();

   leds->setStartState();
   lcd->setStartScreen();
   buzzer->startupSound();

   numberPad->attach(this, &Board::buttonEvent);
   numberPad->start();
}

uint32_t Board::buttonEvent(uint32_t index){
    printf("Pushed button: %c",NumberPad::KEYS[index]);
    buzzer->keypadBeep(NumberPad::KEYS[index]);
    lcd->eventHandler(NumberPad::KEYS[index]);
    return 0;
}
