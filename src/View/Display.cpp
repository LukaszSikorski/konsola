#include "Display.h"

void Display::fill(Matrix &matrix){
    this->spi.sendBytes(128 + 1,1 + 16,~2,~1);
}