#pragma once

#include <string>
#include <vector>
#include "Location.h"
#include "Board.h"

class Mission{
    private:
       std::string name;
       std::string description;
       int id;
       std::vector<Location *> locations;
       Board * board;
        
        
    public:
        Mission(std::string name, int id, std::string description);
        void debug(Serial * serial);
        
    public: //Getters
        std::string getName();
        std::string getDescription();
        double getLatitude();
        double getLongitude();
        double getRadius();
        int getId();
        double getDistanceToTarget();
        bool isComplete();
        int getIndexOfClosestArea();
        
    public: //Setters
        void addTargetLocation(Location* location);
        void attachBoard(Board* board);

};