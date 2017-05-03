#pragma once

#include "Game.h"
#include "logable.h"

class GameCreator : public LogItNow::Logable {
    public:
        static Game* createInstance(char * buffer, Log::LoggerInterface * logger = 0);
};
