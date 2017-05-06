#include "Game.h"
#include "mbed.h"

Game::Game(Log::LoggerInterface * logger) {
    set_logger(logger);
    this->linkedList = new LinkedList();
    currentMission = NULL;
    complete = false;
}

void Game::run(){
   //If mission complete, request new mission
    if( currentMission->isComplete() ) loadNextMission();
}

void Game::debug(){
    if(currentMission == NULL) logger->warning("No current mission");
    else{
      logger->debug("Mission Name: %s", currentMission->getName().c_str());
      logger->debug("Mission ID: %i", currentMission->getId());
      logger->debug("Mission Description: %s", currentMission->getDescription().c_str());
      currentMission->debug();
    }
}

void Game::loadNextMission(){
    if(currentMission == NULL){
        this->currentNode = this->linkedList->getFirstNode();
        this->currentMission = currentNode->getData();
        this->currentMission->attachBoard(board);
    }
    else{
        this->currentNode = this->currentNode->getNextNode();
        if(this->currentNode == NULL){
            //Geen missions meer
            this->board->lcd->setEndScreen();
            this->currentMission = NULL;
            complete = true;
        }
        else{
            this->currentMission = this->currentNode->getData();
            this->currentMission->attachBoard(board);
        }

    }

}


void Game::addMission(Mission * mission){
    this->linkedList->addNode(mission);
}

void Game::addBasicValues(std::string name, std::string box_description, int length, int time){
    this->name = name;
    this->box_description = box_description;
    this->length = length;
    this->time = time;
}


int Game::getCurrentMissionId(){
    if(this->currentMission == NULL) return 0;
    else return this->currentMission->getId();
}

void Game::attachBoard(Board* board){
    this->board = board;
}

bool Game::isComplete(){
    return this->complete;
}

void Game::toLcd(){
    if(isComplete()) this->board->lcd->setMessageScreen("No missions available");
    else if(!board->gps->fix) this->board->lcd->setMessageScreen("Waiting for GPS...");
    else{
        this->currentMission->toLcd();
    }
}
