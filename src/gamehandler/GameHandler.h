#pragma once

#include "Board.h"
#include "Game.h"

class GameHandler {
    private:
        static const float LCD_INTERVAL;

        Board * board;
        bool gameRunning;
        Thread lcd_thread;

    public:
        Game * game;

    public:
        GameHandler(char * buffer, Board * board);
        void run();
        void toLcd();
};
