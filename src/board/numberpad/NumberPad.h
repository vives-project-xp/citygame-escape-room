#pragma once

#include "mbed.h"
#include "Keypad.h"

class NumberPad : public Keypad{

    public:
        NumberPad();

    public:
        void runThisMethod(int index);
        template<class T>
        void attach(T* item, uint32_t(T::*method)(uint32_t)){
            _callback.attach(item, method);
        }

        static const char KEYS[];
};
