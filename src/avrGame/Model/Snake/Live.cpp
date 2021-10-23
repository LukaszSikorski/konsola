#include "Live.h"

Live::Live(){
    this->cycle = 5;
}

Live::Live(uint8_t cycle){
    this->cycle = cycle;
}


Chunk *Live::getChunk(){
    return &this->chunk;
}

Live *Live::setChunk(const Chunk *chunk){
    this->chunk = *chunk;
    return this;
}

bool Live::operator==(const Chunk *chunk){
    return this->chunk == *chunk;
}

Live* Live::operator--(){
    if(this->cycle > -ROUND_FOR_NEW_LIVE) this->cycle--;
    return this;
}

bool Live::isCycleZero(){
    return this->isCycleEqual(0);
}

void Live::setCycle(int8_t cycle){
    this->cycle = cycle;
}

bool Live::isCycleEqual(const int8_t cycle){
    bool result = false;
    if(this->cycle == cycle){
        result = true;
    }
    return result;
}