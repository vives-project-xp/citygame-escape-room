#pragma once

#include "Mission.h"
#include "MbedJSONValue.h"
#include "logable.h"

class MissionCreator : public LogItNow::Logable{

    public:
        static Mission * createInstance(MbedJSONValue & json, Log::LoggerInterface * logger = 0);

};
