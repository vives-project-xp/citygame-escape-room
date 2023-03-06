#pragma once

#include "mbed.h"
#include "Keypad.h"

class NumberPad : public Keypad{

    public:
        NumberPad();

    public:
        void runThisMethod(int index);
        void attach(mbed::Callback<void(uint32_t)>);

        static const char KEYS[];
};
