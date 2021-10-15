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

void State::reactOnButtonRightA(void){
}

void State::reactOnButtonRightB(void){
}

void SnakeState::reactOnButtonLeftA(void){
    Logic::moveUp();
    avrGame::ToggleLed();   
}

void SnakeState::reactOnButtonLeftB(void){
    Logic::moveDown();
}

void SnakeState::reactOnButtonRightA(void){
    Logic::moveRight();
    avrGame::ToggleLed();
    
}

void SnakeState::reactOnButtonRightB(void){
    Logic::moveLeft();
}


void SnakeState::capture(){
    if(!Logic::timerMove){
        Logic::moveSnake(&this->snake);
        Logic::timerMove = 100;
    }
    Logic::drawSnake(this->snake, avrGame::_matrix);
}

void SnakeState::update(){
    if (Logic::timerMove)Logic::timerMove--;
}
