#include "Snake.h"
#include "../../avrGame.h"

Chunk::Chunk(uint8_t x, uint8_t y){
    this->x = x;
    this->y = y;
}

Chunk::Chunk(){
    this->x = 0;
    this->y = 0;
}

void Chunk::clear(){
    this->x = 0;
    this->y = 0;
}

void Chunk::moveTo(const uint8_t x,const uint8_t y) {
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
    if (x == 0) x = 8;
    else if(x > 8 ) x = 1;
    this->x = x;
}

void Chunk::setY(uint8_t y){
    if (y == 0) y = 8;
    else if(y > 8 ) y = 1;
    this->y = y;
}

uint8_t Chunk::getX()const{
    return this->x;
}

uint8_t Chunk::getY()const{
    return this->y;
}

bool Chunk::operator==(const Chunk &chunk)const{
    bool result = false;
    if (this->x == chunk.getX() && this->y == chunk.getY()){
        result = true;
    }
    return result;
}

bool Chunk::operator!=(const Chunk &chunk)const{
    bool result = true;
    result = ! this->operator==(chunk);
    return result;
}

void Chunk::show()const {
    // avrGame::rs232.sendStr("x = ");
    // avrGame::rs232.sendInt(x);
    // avrGame::rs232.sendStr(" ,y = ");
    // avrGame::rs232.sendInt(y);
    // avrGame::rs232.sendStr("\n\r");
}

void Chunk::restore(MementoChunk *mementoChunk){
    this->setX(mementoChunk->getX());
    this->setY(mementoChunk->getY());
}

MementoChunk Chunk::save(){
    return MementoChunk(this, x, y);
}



Snake::Snake(const uint8_t lives){
    this->lives = lives;
    clear();
}

void Snake::clear(){
    for( uint8_t i = 0;i < lenght;i++){
        chunks[i].clear();
    }
    this->lenght = 3;
    this->chunks[0].moveTo(3,3);
    this->chunks[1].moveTo(3,4);
    this->chunks[2].moveTo(3,5);
    this->direction = Direction::stop;
    this->lives = SNAKE_LIVES;

}

void Snake::restore(MementoSnake *mementoSnake){
    // this->lives = mementoSnake->lives;
    this->lenght = mementoSnake->lenght;
    this->direction = mementoSnake->direction;
    for (uint8_t i = 0; i < this->lenght; i++){
        this->chunks[i].restore(mementoSnake->getMementoChunk(i));
    }

}

MementoChunk::MementoChunk(Chunk *chunk, uint8_t x, uint8_t y){
    this->chunk = chunk;
    this->x = x;
    this->y = y;
}


MementoChunk::MementoChunk(){
    this->x = 0;
    this->y = 0;
}

uint8_t MementoChunk::getX(){
    return this->x;
}

uint8_t MementoChunk::getY(){
    return this->y;
}

MementoSnake::MementoSnake(Snake *snake, uint8_t lenght, int8_t lives, Chunk *chunks, Direction::Direction direction){
    this->snake = snake;
    this->lenght = lenght;
    // this->lives = lives;
    this->direction = direction;
    this->createMemenotChunks(chunks);
}

MementoSnake::MementoSnake(){

}

void MementoSnake::createMemenotChunks(Chunk *ptrPhunks){
    for(uint8_t i = 0; i < SIZE_SNAKE; i++){
        this->chunks[i] = ptrPhunks[i].save();
    }
}

void MementoSnake::restore(){
    this->snake->restore(this);
}

MementoChunk *MementoSnake::getMementoChunk(uint8_t index){
    return &this->chunks[index];
}