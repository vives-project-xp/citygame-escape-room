#include "LocationMission.h"
#include <cfloat>

LocationMission::LocationMission(std::string name, int id, std::string description, int typeId): Mission(name, id, description, typeId){
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

void LocationMission::debug(Serial * serial){
    serial->printf("Target location: %5.6f , %5.6f\n", getLatitude(), getLongitude());
    serial->printf("Radius: %f \n", getRadius());
    if(board->gps->fix) serial->printf("Distance to target: %f \n", getDistanceToTarget());
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
