#include "GameHandler.h"
#include "GameCreator.h"

GameHandler::GameHandler(char * buffer, Board * board){
    this->board = board;
    game = GameCreator::createInstance(buffer);
    game->attachBoard(this->board);
    game->loadNextMission();
    gameRunning = true;
    lcd_ticker.attach(game,&Game::toLcd, LCD_INTERVAL);
}


void GameHandler::run(){
    if(game->isComplete()) gameRunning = false;
    if(gameRunning) game->run();
} 