#include "State.h"
#include "Model.h"
#include "../avrGame.h"
#include "../View/Colors.h"
#include <util/delay.h>

State::State(Model *model){
    this->model = model;
}

SnakeState::SnakeState(Model *model):State(model){
    rect = avrGame::rect(2, 2, 2, 2);
}

void State::reactOnButtonLeftA(void){

}

void SnakeState::reactOnButtonLeftA(void){
    y++;
    rect.move(x,y);
}

void State::capture(){

}

void SnakeState::capture(){
    avrGame::draw.rect(*model->matrix, rect, Colors::red);
}
