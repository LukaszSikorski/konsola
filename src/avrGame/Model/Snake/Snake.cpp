#include "Snake.h"


Chunk::Chunk(uint8_t x, uint8_t y){
    this->x = x;
    this->y = y;
}

Chunk::Chunk(){
    this->x = 0;
    this->y = 0;
}

void Chunk::moveTo(uint8_t x, uint8_t y) {
    setX(x);
    setY(y);
}

void Chunk::moveTo(Chunk *chunk) {
    this->moveTo(chunk->getX(), chunk->getY());
}

void Chunk::move(uint8_t x, uint8_t y) {
    setX(this->x + x);
    setY(this->y + y);
}

void Chunk::setX(uint8_t x){
    if (x > 250) x = 8;
    else if(x > 8 ) x = 0;
    this->x = x;
}

void Chunk::setY(uint8_t y){
    if (y > 250) y = 8;
    else if(y > 8 ) y = 0;
    this->y = y;
}

uint8_t Chunk::getX()const{
    return this->x;
}

uint8_t Chunk::getY()const{
    return this->y;
}

bool Chunk::operator==(const Chunk &chunk){
    bool result = false;
    if (this->x == chunk.getX() && this->y == chunk.getY()){
        result = true;
    }
    return result;
}

Snake::Snake(){
    this->lenght = 3;
    this->chunks[0].moveTo(3,3);
    this->chunks[1].moveTo(3,4);
    this->chunks[2].moveTo(3,5);
}

