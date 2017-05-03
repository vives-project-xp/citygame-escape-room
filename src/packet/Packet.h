#pragma once

#include "Gps.h"
#include "Game.h"

class Packet
{
public:
    static uint8_t* build(Gps* gps, Game* game);
};

