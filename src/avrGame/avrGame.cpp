#include "avrGame.h"


Matrix avrGame::matrix(){
    return avrGame::_matrix;
}

Draw avrGame::draw = Draw();
Display avrGame::display = Display();
Matrix avrGame::_matrix = Matrix();
Controller avrGame::controller = Controller();
Rect avrGame::rect(uint8_t width, uint8_t height, uint8_t x, uint8_t y){
    return Rect(x, y, width, height);
}