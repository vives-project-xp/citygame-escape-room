#include "KeyMission.h"

KeyMission::KeyMission(std::string name, int id, std::string description, int typeId, Log::LoggerInterface * logger): Mission(name, id, description, typeId, logger){
}

void KeyMission::debug(){
    logger->debug("Key turned: %s", board->keys->isKeyTurned() ? "YES" : "NO");
}

bool KeyMission::isComplete(){
    if(board->keys->isKeyTurned()){
        board->buzzer->completeSound();
        return true;
    }
    else return false;
}

void KeyMission::toLcd(){
    this->board->lcd->setMessageScreen(getDescription());
}
