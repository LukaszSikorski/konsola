#include "State.h"
#include "Model.h"
#include "../avrGame.h"
#include "../View/Colors.h"
#include <util/delay.h>
#include "Games/Logic/Logic.h"


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
    if(snake.direction == Direction::stop){
        this->model->state = this->model->animationState.setTarget(&this->model->menuStateSnake);
        init();
    }
}

void SnakeState::reactOnButtonLeftB(void){
    snake.direction = Direction::stop;
    Logic::pause = true;
}

void SnakeState::reactOnButtonTop(void){
    Logic::moveUp( &this->snake);
    Logic::pause = false;

}

void SnakeState::reactOnButtonDown(void){
    Logic::moveDown(&this->snake);
    Logic::pause = false;

}

void SnakeState::reactOnButtonRight(void){
    Logic::moveRight(&this->snake);
    Logic::pause = false;

}

void SnakeState::reactOnButtonLeft(void){
    Logic::moveLeft(&this->snake);
    Logic::pause = false;

}


void SnakeState::capture(){
    if(!Logic::timerMove ){
        if(Logic::pause == false){
            this->careTaker.saveSnapShot(&this->snake);
            Logic::moveSnake(&this->snake);
            if( Logic::isCollsion(&this->snake)){
                this->snake.lives--;
                if( this->snake.lives > 0){
                    this->careTaker.undo();
                    // Logic::timerMove = 1000;
                    this->model->animationState.setTarget(this, false);
                    Logic::pause = true;
                }
                else{
                    Logic::timerMove = 500;
                    // Logic::addNewScore(&snake);
                    this->model->animationState.setTarget(this, true);
                    // this->snake.clear();
                    return;
                }
            }
        }
        Logic::timerMove = Logic::timeMove;
        Logic::drawSnake(this->snake, avrGame::_matrix);
        Logic::drawScore(SNAKE_SCORE, avrGame::_matrix);
        Logic::drawLive(Colors::purple, avrGame::_matrix);
        avrGame::display.flip(&avrGame::_matrix);
    }
}

void SnakeState::update(){
    if (Logic::timerMove)Logic::timerMove--;
}

void SnakeState::init(){
    this->snake.clear();
    Logic::score = Logic::getNewChunk(&snake);
    Logic::live.chunk = Chunk(0, 0);
    Logic::timerMove = 1;
    Logic::pause = true;
    avrGame::_matrix.fill();
    avrGame::display.flip(&avrGame::_matrix);
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
    this->timerAnimation = TIMER_ANIMATION;
    this->loading = 0;
    this->ini = true;
}

void AnimationState::drawAnimation(){
        if(loading < 10){
        timerAnimation--;
        if(! timerAnimation){

            for(uint8_t i = 1; i <= loading; i++){
                for (uint8_t j = 1; j <= 8; j++){
                    avrGame::draw.point(avrGame::_matrix, i, j, COLOR_ANIMATION);

                }
            }
            avrGame::display.flip(&avrGame::_matrix);
            loading++;
            timerAnimation = TIMER_ANIMATION;
        }
        return;
    }
    if(ini){
        this->targetState->init();
    }
    this->init();
    this->model->state = this->targetState;
}

void AnimationState::capture(){
    this->drawAnimation();
}

State *AnimationState::setTarget(State *target, bool init){
    this->ini = init;
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
    Logic::timeMove = (SIZE_SPEED * 15) - (levelSpeed * 15) + 10;
    this->model->state = this->model->animationState.setTarget(&this->model->snakeState);
}

void MenuStateSnake::reactOnButtonLeftB(void){
    Logic::timeMove = (SIZE_SPEED * 15) - (levelSpeed * 15) + 25;
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
    // avrGame::draw.point(avrGame::_matrix, 2, 2, SNAKE_TAIL);
    // avrGame::draw.point(avrGame::_matrix, 3, 3, SNAKE_TAIL);
    // avrGame::draw.point(avrGame::_matrix, 4, 4, SNAKE_SCORE);
    avrGame::_matrix.flip();
}

// void MenuStateTest::reactOnButtonLeftA(void){

// }

// void MenuStateTest::reactOnButtonLeftB(void){

// }

void MenuStateTest::reactOnButtonTop(void){
    this->model->state = this->model->animationState.setTarget(&this->model->snakeState);
}

