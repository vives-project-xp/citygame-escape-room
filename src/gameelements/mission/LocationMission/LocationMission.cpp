#include "LocationMission.h"
#include <cfloat>

LocationMission::LocationMission(std::string name, int id, std::string description, int typeId, Log::LoggerInterface * logger): Mission(name, id, description, typeId, logger){
}

int LocationMission::getIndexOfClosestArea(){
    double distance = DBL_MAX;
    int index=0;
    for(int i=0; i < locations.size(); i++){
        double tempDist = locations[i]->getDistanceToTarget(this->board) - locations[i]->getRadius();
        if(tempDist < distance){
            distance = tempDist;
            index = i;
        }
    }
    return index;
}

void LocationMission::debug(){
    logger->debug("Target location: %5.6f , %5.6f", getLatitude(), getLongitude());
    logger->debug("Radius: %f ", getRadius());
    if(board->gps->fix) logger->debug("Distance to target: %f ", getDistanceToTarget());
}

bool LocationMission::isComplete(){
    if(getDistanceToTarget() < getRadius()) return true;
    else return false;
}

double LocationMission::getLatitude(){
    return locations[getIndexOfClosestArea()]->getLatitude();
}

double LocationMission::getLongitude(){
    return locations[getIndexOfClosestArea()]->getLongitude();
}

double LocationMission::getRadius(){
    return locations[getIndexOfClosestArea()]->getRadius();
}


void LocationMission::addTargetLocation(Location * location){
    locations.push_back(location);
}

double LocationMission::getDistanceToTarget(){
    return locations[getIndexOfClosestArea()]->getDistanceToTarget(this->board);
}

void LocationMission::toLcd(){
    this->board->lcd->setMissionScreen(getDescription(),(int)getDistanceToTarget(),(int)getRadius());
    this->board->leds->reactToDistance((int)getDistanceToTarget(), (int)getRadius());
}
