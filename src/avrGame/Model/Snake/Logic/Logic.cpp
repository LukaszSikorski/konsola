#include "Logic.h"

uint16_t Logic::timerMove = 200;
uint16_t Logic::timeMove = 200;
Chunk Logic::score = Chunk(2,2);
Chunk Logic::live = Chunk(0,0);
bool Logic::pause = false;

void Logic::drawChunk(Chunk &chunk,Colors color, Matrix &matrix){
    uint8_t x = chunk.getX();
    uint8_t y = chunk.getY();
    Rect rect = avrGame::rect(x, y, 1, 1);
    avrGame::draw.rect(matrix, rect, color);

}

void Logic::drawScore(Colors color, Matrix &matrix){
    Logic::drawChunk(Logic::score, color, matrix);
}

void Logic::drawLive(Colors color, Matrix &matrix){
    Logic::drawChunk(Logic::live, color, matrix);

}

void Logic::moveChunk( Chunk *chunk, Direction::Direction const *direction){
    if(*direction == Direction::left){
        chunk->move(-1, 0);
    }
    else if (*direction == Direction::right){
        chunk->move(1, 0);
    }
    else if (*direction == Direction::up){
        chunk->move(0, -1);
    }
    else if (*direction == Direction::down){
        chunk->move(0, 1);
    }
}

void Logic::moveSnake(Snake *snake){
    if (snake->direction != Direction::stop){
        Chunk last = snake->chunks[ snake->lenght - 1];
        for(uint8_t i = snake->lenght - 1; i > 0; i--){
            Chunk *next = &snake->chunks[i - 1];
            snake->chunks[i].moveTo(next);
        }
        Logic::moveChunk(&snake->chunks[0], &snake->direction);
        if (Logic::isOnScore(snake, &Logic::score)){
            Logic::addChunkToSnake(snake, &last);
            Logic::addNewScore(snake);
        }
    }

}

void Logic::moveLeft(Snake *snake){
    if (snake->direction != Direction::right) snake->direction = Direction::left;
}

void Logic::moveRight(Snake *snake){
    if (snake->direction != Direction::left) snake->direction = Direction::right;
}

void Logic::moveUp(Snake *snake){
    if (snake->direction != Direction::down) snake->direction = Direction::up;
}

void Logic::moveDown(Snake *snake){
    if (snake->direction != Direction::up) snake->direction = Direction::down;
}

void Logic::drawSnake(Snake &snake, Matrix &matrix){
    Chunk *chunk;
    for(uint8_t i = 1; i < snake.lenght; i++){
        Chunk *chunk = &snake.chunks[i];
        Logic::drawChunk(*chunk, SNAKE_TAIL, matrix);
    }
    chunk = &snake.chunks[0];
    Logic::drawChunk(*chunk, SNAKE_HEAD,matrix);
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
    for (uint8_t i = 0; i < snake->lenght; i++){
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

bool Logic::isCollsion(Snake *snake){
    bool result = false;
    Chunk *head = &snake->chunks[0];
    for (uint8_t i = 1;i < snake->lenght; i++){
        if ( *head == snake->chunks[i] ){
            result = true;
            break;
        }
    }
    return result;
}