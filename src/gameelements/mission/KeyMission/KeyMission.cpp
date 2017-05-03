#include "KeyMission.h"

KeyMission::KeyMission(std::string name, int id, std::string description, int typeId): Mission(name, id, description, typeId){
}    

void KeyMission::debug(Serial * serial){
    serial->printf("Key turned: %s\n", board->keys->isKeyTurned() ? "YES" : "NO");
}

bool KeyMission::isComplete(){
    if(board->keys->isKeyTurned()) return true;
    else return false;
}

void KeyMission::toLcd(){
    this->board->lcd->setMessageScreen(getDescription());  
}
    