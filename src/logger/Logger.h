#pragma once

#include "mbed.h"
#include "Packet.h"
#include "Gps.h"
#include "Game.h"

class Logger
{
public:
    Logger(Serial* serial);
    void packet(uint8_t* packet);
    void gps(Gps* gps);
    void game(Game* game);
private:
    Serial* serial;
};

