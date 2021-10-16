#include "Logic.h"

Direction::Direction Logic::direction = Direction::stop;
uint16_t Logic::timerMove = 500;
Chunk Logic::score = Chunk(2,2);

void Logic::drawChunk(Chunk &chunk,Colors color, Matrix &matrix){
    uint8_t x = chunk.getX();
    uint8_t y = chunk.getY();
    Rect rect = avrGame::rect(x, y, 1, 1);
    avrGame::draw.rect(matrix, rect, color);

}

void Logic::drawScore(Colors color, Matrix &matrix){
    Logic::drawChunk(Logic::score, color, matrix);
}

void Logic::moveChunk( Chunk *chunk){
    if(Logic::direction == Direction::left){
        chunk->move(-1, 0);
    }
    else if (Logic::direction == Direction::right){
        chunk->move(1, 0);
    }
    else if (Logic::direction == Direction::up){
        chunk->move(0, -1);
    }
    else if (Logic::direction == Direction::down){
        chunk->move(0, 1);
    }
}

void Logic::moveSnake(Snake *snake){
    if (Logic::direction != Direction::stop){
        Chunk last = snake->chunks[ snake->lenght - 1];
        for(uint8_t i = snake->lenght - 1; i > 0; i--){
            Chunk *next = &snake->chunks[i - 1];
            snake->chunks[i].moveTo(next);
        }
        Logic::moveChunk(&snake->chunks[0]);
        if (Logic::isOnScore(snake, &Logic::score)){
            Logic::addChunkToSnake(snake, &last);
            Logic::addNewScore(snake);
        }
    }

}

void Logic::moveLeft(){
    if (Logic::direction != Direction::right) Logic::direction = Direction::left;
}

void Logic::moveRight(){
    if (Logic::direction != Direction::left) Logic::direction = Direction::right;
}

void Logic::moveUp(){
    if (Logic::direction != Direction::down) Logic::direction = Direction::up;
}

void Logic::moveDown(){
    if (Logic::direction != Direction::up) Logic::direction = Direction::down;
}

void Logic::drawSnake(Snake &snake, Matrix &matrix){
    Chunk *chunk;
    for(uint8_t i = 1; i < snake.lenght; i++){
        Chunk *chunk = &snake.chunks[i];
        Logic::drawChunk(*chunk, Colors::red,matrix);
    }
    chunk = &snake.chunks[0];
    Logic::drawChunk(*chunk, Colors::green,matrix);
}

bool Logic::isOnScore(Snake *snake, Chunk *chunk){
    bool result = false;
    if( snake->chunks[0] == *chunk ){
        result = true;
    }
    return result;
}

void Logic::addChunkToSnake(Snake *snake, Chunk *chunk){
    snake->chunks[snake->lenght] = *chunk;
    snake->lenght++;
}

uint8_t Logic::getRandomPos(uint8_t from , uint8_t to){
    uint16_t result = 0;
    uint8_t mux = to - from;
    result = (avrGame::adc.getSingle(5) % mux) + from;
    return (uint8_t)(result);
}

Chunk Logic::getRandomChunk(){
    uint8_t x = Logic::getRandomPos(1, 9);
    uint8_t y = Logic::getRandomPos(1, 9);
    Chunk chunk = Chunk(x, y);
    return chunk;
}

bool Logic::isFreePos( Snake *snake, Chunk *chunk){
    bool result = true;
    for (uint8_t i = 0; i < snake->lenght - 1; i++){
        if (snake->chunks[i] == *chunk){
            result = false;
            break;
        }
    }
    return result;
}

void Logic::addNewScore(Snake *snake){
    bool condition = false;
    Chunk chunk;
    while (!condition){
        chunk = Logic::getRandomChunk();
        condition = Logic::isFreePos(snake, &chunk);
    }
    Logic::score = chunk;
}