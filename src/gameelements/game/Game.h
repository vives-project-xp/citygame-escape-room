#pragma once

#include "Mission.h"
#include <string>
#include "LinkedList.h"
#include "LinkableNode.h"
#include "Board.h"
#include "logable.h"

class Game : public LogItNow::Logable {
    private:
        std::string name;
        std::string box_description;

        int length;
        int time;

        bool complete;

        Mission * currentMission;
        LinkedList * linkedList;
        LinkableNode * currentNode;
        Board * board;

    public:
        Game(Log::LoggerInterface * logger = 0);

    public:
        void run();
        void debug();
        void loadNextMission();
        void toLcd();

    public:
        int getCurrentMissionId();
        bool isComplete();

    public:
        void addMission(Mission* mission); //adds a mission to the linked list
        void addBasicValues(std::string name, std::string box_description, int length, int time);
        void attachBoard(Board * board);


};
