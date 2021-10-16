#include "State.h"
#include "Model.h"
#include "../avrGame.h"
#include "../View/Colors.h"
#include <util/delay.h>
#include "Snake/Logic/Logic.h"


State::State(Model *model){
    this->model = model;
}

void State::capture(){

}

void State::update(){

}
SnakeState::SnakeState(Model *model):State(model){

}

void State::reactOnButtonLeftA(void){
}

void State::reactOnButtonLeftB(void){
}

void State::reactOnButtonTop(void){
}

void State::reactOnButtonDown(void){
}

void State::reactOnButtonRight(void){
}

void State::reactOnButtonLeft(void){
}

void SnakeState::reactOnButtonLeftA(void){
    avrGame::ToggleLed();   
}

void SnakeState::reactOnButtonLeftB(void){
}

void SnakeState::reactOnButtonTop(void){
    Logic::moveUp();
    avrGame::ToggleLed();   
}

void SnakeState::reactOnButtonDown(void){
    Logic::moveDown();
}

void SnakeState::reactOnButtonRight(void){
    Logic::moveRight();
}

void SnakeState::reactOnButtonLeft(void){
    Logic::moveLeft();
}


void SnakeState::capture(){
    if(!Logic::timerMove){
        Logic::moveSnake(&this->snake);
        if( Logic::isCollsion(&this->snake)){
            this->snake.clear();
            Logic::direction = Direction::stop;
            return;
        }
        Logic::timerMove = 100;
        Logic::drawSnake(this->snake, avrGame::_matrix);
        Logic::drawScore(Colors::blue, avrGame::_matrix);
        avrGame::display.flip(&avrGame::_matrix);
    }
}

void SnakeState::update(){
    if (Logic::timerMove)Logic::timerMove--;
}
