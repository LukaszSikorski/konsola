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
    init();
}

void SnakeState::reactOnButtonLeftA(void){
    avrGame::ToggleLed();  
    if(snake.direction == Direction::stop){
        this->model->state = this->model->animationState.setTarget(&this->model->menuStateSnake);
        init();
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
            Logic::addNewScore(&snake);
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
    avrGame::_matrix.fill();
    avrGame::display.flip(&avrGame::_matrix);
    Logic::timerMove = 1;
}
MenuState::MenuState(Model *model):State(model){
    index = 0;
    games = Games::snake;
    this->states[0] = &model->menuStateSnake,
    this->states[1] = &model->menuStateTest,
    this->current = states[index];
}

void MenuState::reactOnButtonLeftA(void){
    this->model->state = this->model->animationState.setTarget(this->current);

}

void MenuState::reactOnButtonLeftB(void){

}

void MenuState::reactOnButtonTop(void){

}

void MenuState::reactOnButtonDown(void){
}

void MenuState::reactOnButtonRight(void){
    index++;
    if(index >= SIZE_STATES) index = 0;
}

void MenuState::reactOnButtonLeft(void){
    index--;
    if (index < 0) index = SIZE_STATES - 1;
    
}

void MenuState::capture(){
    this->current = states[index];
    this->current->capture();

}
void MenuState::update(){
}

void MenuState::init(){
}




AnimationState::AnimationState(Model *model):State(model){
    init();
}


void AnimationState::init(){
    timerAnimation = 150;
    loading = 0;
}

void AnimationState::drawAnimation(){
        if(loading < 10){
        timerAnimation--;
        if(! timerAnimation){

            for(uint8_t i = 1; i <= loading; i++){
                for (uint8_t j = 1; j <= 8; j++){
                    avrGame::draw.point(avrGame::_matrix, i, j, Colors::green);

                }
            }
            avrGame::display.flip(&avrGame::_matrix);
            loading++;
            timerAnimation = TIMER_ANIMATION;
        }
        return;
    }
    this->init();
    this->targetState->init();
    this->model->state = this->targetState;
}

void AnimationState::capture(){
    this->drawAnimation();
}

State *AnimationState::setTarget(State *target){
    this->model->state = &this->model->animationState;
    this->model->animationState.targetState = target;
    return this;
}

MenuStateSnake::MenuStateSnake(Model *model):State(model){

}

void MenuStateSnake::capture(){
    avrGame::draw.point(avrGame::_matrix, 4, 4, SNAKE_HEAD);
    avrGame::draw.point(avrGame::_matrix, 4, 5, SNAKE_TAIL);
    avrGame::draw.point(avrGame::_matrix, 4, 6, SNAKE_TAIL);
    avrGame::draw.point(avrGame::_matrix, 6, 3, SNAKE_SCORE);
    drawLevelSpeed();
    avrGame::_matrix.flip();
}

void MenuStateSnake::reactOnButtonLeftA(void){
    Logic::timeMove = (SIZE_SPEED * 20) - (levelSpeed * 20) + 10;
    this->model->state = this->model->animationState.setTarget(&this->model->snakeState);
}

void MenuStateSnake::reactOnButtonLeftB(void){
    Logic::timeMove = (SIZE_SPEED * 20) - (levelSpeed * 20) + 10;
    this->model->state = this->model->animationState.setTarget(&this->model->menuState);
}

void MenuStateSnake::reactOnButtonTop(void){

}

void MenuStateSnake::reactOnButtonLeft(){
    levelSpeed--;
    if(levelSpeed > SIZE_SPEED || levelSpeed == 0){
        levelSpeed = 1;
    }
}

void MenuStateSnake::reactOnButtonRight(){
    levelSpeed++;
    if(levelSpeed > SIZE_SPEED){
        levelSpeed = SIZE_SPEED;
    }
}

void MenuStateSnake::drawLevelSpeed(){
    for(uint8_t i = 1; i < (levelSpeed + 1); i++){
        avrGame::draw.point(avrGame::_matrix, i, 1, Colors::purple);
    }
}

MenuStateTest::MenuStateTest(Model *model):State(model){

}

void MenuStateTest::capture(){
    avrGame::draw.point(avrGame::_matrix, 1, 1, SNAKE_HEAD);
    avrGame::draw.point(avrGame::_matrix, 2, 2, SNAKE_TAIL);
    avrGame::draw.point(avrGame::_matrix, 3, 3, SNAKE_TAIL);
    avrGame::draw.point(avrGame::_matrix, 4, 4, SNAKE_SCORE);
    drawLevelSpeed();
    avrGame::_matrix.flip();
}

void MenuStateTest::reactOnButtonLeftA(void){
    levelSpeed++;
    if(levelSpeed > SIZE_SPEED){
        levelSpeed = SIZE_SPEED;
    }
}

void MenuStateTest::reactOnButtonLeftB(void){
    levelSpeed--;
    if(levelSpeed > SIZE_SPEED || levelSpeed == 0){
        levelSpeed = 1;
    }
}

void MenuStateTest::reactOnButtonTop(void){
    Logic::timeMove = (SIZE_SPEED * 20) - (levelSpeed * 20) + 10;
    this->model->state = this->model->animationState.setTarget(&this->model->snakeState);
}

void MenuStateTest::drawLevelSpeed(){
    for(uint8_t i = 1; i < (levelSpeed + 1); i++){
        avrGame::draw.point(avrGame::_matrix, i, 1, Colors::purple);
    }
}
