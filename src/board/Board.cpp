#include "Board.h"
#include "Lcd.h"
#include "Display.h"

I2C i2c(PTE25, PTE24);

Board::Board(){
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
