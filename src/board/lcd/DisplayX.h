#pragma once
#include <string>

class DisplayX{
    
    public:
        virtual void setEndScreen() = 0;
        virtual void setStartScreen() = 0 ;
        virtual void setMessageScreen(std::string message) = 0;
        virtual void setMissionScreen(std::string description, int distance, int radius) = 0; 
    
};