#include "NumberPad.h"

const char NumberPad::KEYS[] = {'1','2','3','4','5','6','7','8','9','*','0','#'};

NumberPad::NumberPad() : Keypad(PTC4, PTB23, PTC2, PTE26, PTB20, PTB2, PTC3, NC){

}
