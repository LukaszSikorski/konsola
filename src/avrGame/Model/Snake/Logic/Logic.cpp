#include "Logic.h"

Direction::Direction Logic::direction = Direction::stop;
uint16_t Logic::timerMove = 500;

void Logic::drawChunk(Chunk &chunk,Colors color, Matrix &matrix){
    uint8_t x = chunk.getX();
    uint8_t y = chunk.getY();
    Rect rect = avrGame::rect(x, y, 1, 1);
    avrGame::draw.rect(matrix, rect, color);

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
    Chunk ch(1,1);
    if (Logic::direction != Direction::stop){
        Chunk last = snake->chunks[ snake->lenght - 1];
        for(uint8_t i = snake->lenght - 1; i > 0; i--){
            Chunk *next = &snake->chunks[i - 1];
            snake->chunks[i].moveTo(next);
        }
        Logic::moveChunk(&snake->chunks[0]);
        if (Logic::isOnScore(snake, &ch)){
            Logic::addChunkToSnake(snake, &last);
        }
    }

}

void Logic::moveLeft(){
    Logic::direction = Direction::left;
}

void Logic::moveRight(){
    Logic::direction = Direction::right;
}

void Logic::moveUp(){
    Logic::direction = Direction::up;
}

void Logic::moveDown(){
    Logic::direction = Direction::down;
}

void Logic::drawSnake(Snake &snake, Matrix &matrix){
    Chunk *chunk;
    for(uint8_t i = 1; i < snake.lenght; i++){
        Chunk *chunk = &snake.chunks[i];
        Logic::drawChunk(*chunk, Colors::red,matrix);
    }
    chunk = &snake.chunks[0];
    Logic::drawChunk(*chunk, Colors::white,matrix);
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