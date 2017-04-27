#pragma once

#include "Lora.h"
#include "Leds.h"
#include "DisplayX.h"
#include "Keys.h"
#include "Gps.h"
#include "Buzzer.h"

class Board{

    public:
        Lora * lora;
        Leds * leds;
        DisplayX * lcd;
        Keys * keys;
        Gps * gps;
        Buzzer * buzzer;
    
    public:
        Board();

};