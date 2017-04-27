#pragma once

#include "LinkableNode.h"
#include "Mission.h"


    class LinkedList{
    private:
        LinkableNode * headNode;

    public:
        LinkedList();
        ~LinkedList();

    public:
        void addNode(Mission * data);
        void removeNode();
        std::string toString();

    private:
        LinkableNode* getLastNode();
        LinkableNode* getSecondLastNode();
        
    public:
        LinkableNode* getFirstNode();

    };

