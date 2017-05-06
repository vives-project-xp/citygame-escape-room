#pragma once

#include "Mission.h"
#include "logable.h"

class KeyMission : public Mission{

    public:
        KeyMission(std::string name, int id, std::string description, int typeId, Log::LoggerInterface * logger);
        virtual void debug();
        virtual bool isComplete();
        virtual void toLcd();
};
