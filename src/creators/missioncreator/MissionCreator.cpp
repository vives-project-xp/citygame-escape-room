#include "MissionCreator.h"
#include "LocationCreator.h"

Mission* MissionCreator::createInstance(MbedJSONValue & json){
        
        Mission * mission = new Mission(
            json["name"].get<std::string>(),
            json["id"].get<int>(),
            json["description"].get<std::string>()
        ); 
        
        for(int j=0; j < json["locations"].size(); j++){
            mission->addTargetLocation(LocationCreator::createInstance( json["locations"][j]));
        }
    
        return mission;
}




