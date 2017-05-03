#pragma once

#include "Board.h"
#include "Game.h"
#include "logable.h"

class GameHandler : public LogItNow::Logable {
    private:
        static const float LCD_INTERVAL = 3.0;

        Board * board;
        bool gameRunning;
        Thread lcd_thread;

    public:
        Game * game;

    public:
        GameHandler(char * buffer, Board * board, Log::LoggerInterface * logger = 0);
        void run();
        void toLcd();
};
