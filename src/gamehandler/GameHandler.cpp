#include "mbed.h"
#include "GameHandler.h"
#include "GameCreator.h"

const float GameHandler::LCD_INTERVAL = 3.0;

GameHandler::GameHandler(char * buffer, Board * board){
    this->board = board;
    game = GameCreator::createInstance(buffer);
    game->attachBoard(this->board);
    game->loadNextMission();
    gameRunning = true;
    lcd_thread.start(mbed::Callback<void()>(this, &GameHandler::toLcd));
}


void GameHandler::run(){
    if(game->isComplete()) gameRunning = false;
    if(gameRunning) game->run();
}

void GameHandler::toLcd(){
    while(true){
        ThisThread::sleep_for(std::chrono::seconds((int)LCD_INTERVAL));
        game->toLcd();
    }
}
