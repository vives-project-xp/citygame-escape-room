#pragma once

#include "Lora.h"
#include "Leds.h"
#include "DisplayX.h"
#include "Keys.h"
#include "Gps.h"
#include "Buzzer.h"
#include "NumberPad.h"


class Board{

    public:
        Lora * lora;
        Leds * leds;
        DisplayX * lcd;
        Keys * keys;
        Gps * gps;
        Buzzer * buzzer;
        NumberPad * numberPad;

    public:
        Board(Log::LoggerInterface * logger = 0);
        uint32_t buttonEvent(uint32_t index);


};
