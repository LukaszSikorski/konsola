#include "avrGame.h"


Matrix avrGame::matrix(){
    return avrGame::_matrix;
}

Listener avrGame::listene = Listener(&mediato);
Draw avrGame::draw = Draw();
Display avrGame::display = Display();
Matrix avrGame::_matrix = Matrix();
Model avrGame::mode = Model(&_matrix);
Mediator avrGame::mediato = Mediator(&mode);
Controller avrGame::controller = Controller(&listene);
Rect avrGame::rect(uint8_t x, uint8_t y, uint8_t width, uint8_t height){
    return Rect(x, y, width, height);
}

void avrGame::ToggleLed(){
    PORTD ^= (1<<PD4);
}