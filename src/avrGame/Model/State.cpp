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

void State::init(){
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

SnakeState::SnakeState(Model *model):State(model){
}

void SnakeState::reactOnButtonLeftA(void){
    avrGame::ToggleLed();  
    if(snake.direction == Direction::stop){
        this->model->state = &this->model->menuState;
    }
}

void SnakeState::reactOnButtonLeftB(void){
    snake.direction = Direction::stop;
}

void SnakeState::reactOnButtonTop(void){
    Logic::moveUp( &this->snake);
    avrGame::ToggleLed();   
}

void SnakeState::reactOnButtonDown(void){
    Logic::moveDown(&this->snake);
}

void SnakeState::reactOnButtonRight(void){
    Logic::moveRight(&this->snake);
}

void SnakeState::reactOnButtonLeft(void){
    Logic::moveLeft(&this->snake);
}


void SnakeState::capture(){
    if(!Logic::timerMove){
        Logic::moveSnake(&this->snake);
        if( Logic::isCollsion(&this->snake)){
            this->snake.clear();
            Logic::timerMove = 500;
            return;
        }
        Logic::timerMove = Logic::timeMove;
        Logic::drawSnake(this->snake, avrGame::_matrix);
        Logic::drawScore(SNAKE_SCORE, avrGame::_matrix);
        avrGame::display.flip(&avrGame::_matrix);
    }
}

void SnakeState::update(){
    if (Logic::timerMove)Logic::timerMove--;
}

void SnakeState::init(){
    this->snake.clear();
    Logic::timerMove = 500;
}
MenuState::MenuState(Model *model):State(model){
    games = Games::snake;
    levelSpeed = 1;
}

void MenuState::reactOnButtonLeftA(void){
    levelSpeed++;
    if(levelSpeed > SIZE_SPEED){
        levelSpeed = SIZE_SPEED;
    }
}

void MenuState::reactOnButtonLeftB(void){
    levelSpeed--;
    if(levelSpeed > SIZE_SPEED || levelSpeed == 0){
        levelSpeed = 1;
    }
}

void MenuState::reactOnButtonTop(void){
    Logic::timeMove = (SIZE_SPEED * 20) - (levelSpeed * 20) + 10;
    this->model->state = &this->model->snakeState;
    this->model->state->init();
}

void MenuState::reactOnButtonDown(void){
}

void MenuState::reactOnButtonRight(void){
}

void MenuState::reactOnButtonLeft(void){
}

void MenuState::capture(){
    avrGame::draw.point(avrGame::_matrix, 4, 4, SNAKE_HEAD);
    avrGame::draw.point(avrGame::_matrix, 4, 5, SNAKE_TAIL);
    avrGame::draw.point(avrGame::_matrix, 4, 6, SNAKE_TAIL);
    avrGame::draw.point(avrGame::_matrix, 6, 3, SNAKE_SCORE);
    drawLevelSpeed();
    avrGame::_matrix.flip();
}
void MenuState::update(){
}

void MenuState::init(){
}

void MenuState::drawLevelSpeed(){
    for(uint8_t i = 1; i < (levelSpeed + 1); i++){
        avrGame::draw.point(avrGame::_matrix, i, 1, Colors::purple);
    }
}