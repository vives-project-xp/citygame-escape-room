#include "GameHandler.h"
#include "GameCreator.h"

GameHandler::GameHandler(char * buffer, Board * board){
    this->board = board;
    game = GameCreator::createInstance(buffer);
    game->attachBoard(this->board);
    game->loadNextMission();
    gameRunning = true;
    lcd_thread.start(callback(this, &GameHandler::toLcd));
}


void GameHandler::run(){
    if(game->isComplete()) gameRunning = false;
    if(gameRunning) game->run();
}

void GameHandler::toLcd(){
    while(true){
        game->toLcd();
        Thread::wait(LCD_INTERVAL*1000);
    }
}
