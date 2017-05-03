#include "LinkedList.h"
#include <sstream>



    LinkedList::LinkedList(){
        this->headNode = NULL;
    }

    void LinkedList::addNode(Mission * data){
        if(this->headNode == NULL) headNode = new LinkableNode(data);
        else getLastNode()->setNextNode(new LinkableNode(data));
    }

    std::string LinkedList::toString(){
        std::stringstream ss;
        ss << "Data in the linked list:" << std::endl;

        if(this->headNode == NULL){
            ss << "NO DATA IN LIST" << std::endl;
        }
        else{
            LinkableNode * last = this->headNode;
            while(last != NULL){
                ss << last->toString();
                last = last->getNextNode();
            }
            ss << std::endl;
        }

        return ss.str();
    }

    LinkableNode* LinkedList::getLastNode(){
        LinkableNode * last = this->headNode;
        while(last->getNextNode() != NULL){
            last = last->getNextNode();
        }
        return last;
    }

    LinkableNode* LinkedList::getSecondLastNode(){
        LinkableNode * last = this->headNode;
        while(last->getNextNode()->getNextNode() != NULL){
            last = last->getNextNode();
        }
        return last;
    }

    void LinkedList::removeNode(){
        if(this->headNode == NULL){}         //Er is geen hoofdnode -> Niets verwijderen
        else if(this->headNode->getNextNode() == NULL){ //Er is alleen een hoofnode -> hoofdnode verwijderen
            delete this->headNode;
            this->headNode = NULL;
        }
        else{
            delete getSecondLastNode()->getNextNode();
            getSecondLastNode()->setNextNode(NULL);
        }
    }

    LinkedList::~LinkedList(){
        while(this->headNode != NULL){
            removeNode();
        }
    }
    
    LinkableNode* LinkedList::getFirstNode(){
        return this->headNode;
    }

