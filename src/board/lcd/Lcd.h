#pragma once
#include "TextLCD.h"
#include <string>
#include "DisplayX.h"


class Lcd : public DisplayX{
    private:
        TextLCD* lcd;
        PwmOut* backlight;
    public:
        Lcd();
        void setEndScreen();
        void setStartScreen();
        void setMessageScreen(std::string message);
        void setMissionScreen(std::string description, int distance, int radius);
};