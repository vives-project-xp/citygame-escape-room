#include "Mission.h"
#include <string>

    Mission::Mission(std::string name, int id, std::string description){
        this->name = name;
        this->id = id;
        this->description = description;
    }

    std::string Mission::getName(){
        return name;
    }

    int Mission::getId(){
        return id;
    }

    std::string Mission::getDescription(){
        return description;
    }

    double Mission::getLatitude(){
        return locations[getIndexOfClosestArea()]->getLatitude();
    }

    double Mission::getLongitude(){
        return locations[getIndexOfClosestArea()]->getLongitude();
    }

    double Mission::getRadius(){
        return locations[getIndexOfClosestArea()]->getRadius();
    }


    void Mission::addTargetLocation(Location * location){
        locations.push_back(location);
    }

    double Mission::getDistanceToTarget(){
        return locations[getIndexOfClosestArea()]->getDistanceToTarget(this->board);
    }


    bool Mission::isComplete(){
        if(getDistanceToTarget() < getRadius()) return true;
        else return false;
    }

    void Mission::attachBoard(Board* board){
        this->board = board;
    }

    int Mission::getIndexOfClosestArea(){
        double distance = 12756000;
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

    void Mission::debug(Serial * serial){
            serial->printf("Target location: %5.6f , %5.6f\n", getLatitude(), getLongitude());
            serial->printf("Radius: %f \n", getRadius());
            if(board->gps->fix) serial->printf("Distance to target: %f \n", getDistanceToTarget());
    }
