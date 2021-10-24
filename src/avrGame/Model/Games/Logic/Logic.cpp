#include "Logic.h"

uint16_t Logic::timerMove = 200;
uint16_t Logic::timeMove = 200;
Chunk Logic::score = Chunk(2,2);
Live Logic::live = Live(LIVE_CYCLE);
bool Logic::pause = false;

void Logic::drawChunk(Chunk &chunk,Colors color){
    uint8_t x = chunk.getX();
    uint8_t y = chunk.getY();
    Rect rect = avrGame::rect(x, y, 1, 1);
    avrGame::draw.rect(avrGame::_matrix, rect, color);

}

void Logic::drawScore(Colors color){
    Logic::drawChunk(Logic::score, color);
}

void Logic::drawLive(Colors color){
    Logic::drawChunk(*Logic::live.getChunk(), color);

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
    Logic::setDirectionSnake(snake);
    if (snake->direction != Direction::stop){
        Chunk last = snake->chunks[ snake->lenght - 1];
        for(uint8_t i = snake->lenght - 1; i > 0; i--){
            Chunk *next = &snake->chunks[i - 1];
            snake->chunks[i].moveTo(next);
        }
        Logic::moveChunk(&snake->chunks[0], &snake->direction);
        if (Logic::isSnakeOnChunk(snake, &Logic::score)){
            Logic::addChunkToSnake(snake, &last);
            Logic::score = Logic::getNewChunk(snake);
        }
        else if(Logic::isSnakeOnChunk(snake, &Logic::live.chunk)){
            Logic::addLiveToSnake(snake);
            Logic::live.chunk = Chunk(0, 0);
            // Logic::live = Logic::getNewChunk(snake); 
        }
        if(Logic::live.isCycleZero()){
            Logic::live.chunk = Chunk(0, 0);
        }
        if(Logic::live.isCycleEqual(-ROUND_FOR_NEW_LIVE) && snake->lives < MAX_LIVE){
            Logic::live.chunk = Logic::getNewChunk(snake);
            Logic::live.setCycle(LIVE_CYCLE);
        }
        --Logic::live;
    }

}

void Logic::moveLeft(Snake *snake){
    if (snake->lastDirection != Direction::right) snake->lastDirection = Direction::left;
}

void Logic::moveRight(Snake *snake){
    if (snake->lastDirection != Direction::left) snake->lastDirection = Direction::right;
}

void Logic::moveUp(Snake *snake){
    if (snake->lastDirection != Direction::down) snake->lastDirection = Direction::up;
}

void Logic::moveDown(Snake *snake){
    if (snake->lastDirection != Direction::up) snake->lastDirection = Direction::down;
}

void Logic::drawSnake(Snake &snake){
    Chunk *chunk;
    for(uint8_t i = 1; i < snake.lenght; i++){
        Chunk *chunk = &snake.chunks[i];
        Logic::drawChunk(*chunk, SNAKE_TAIL);
    }
    chunk = &snake.chunks[0];
    Logic::drawChunk(*chunk, SNAKE_HEAD);
}

bool Logic::isSnakeOnChunk(Snake *snake, Chunk *chunk){
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
        // TODO: chunk nie potrzebnie przyjemuje wartosc zamiast wskaznika do porownania
        if (snake->chunks[i] == *chunk || Logic::live == chunk || Logic::score == *chunk){
            result = false;
            break;
        }
    }
    return result;
}

Chunk Logic::getNewChunk(Snake *snake){
    bool condition = false;
    Chunk chunk;
    while (!condition){
        chunk = Logic::getRandomChunk();
        condition = Logic::isFreePos(snake, &chunk);
    }
    return chunk;
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

void Logic::addLiveToSnake(Snake *snake){
    if(snake->lives < MAX_LIVE){
        snake->lives++;
        avrGame::ToggleLed();
    }
}

void Logic::setDirectionSnake(Snake *snake){
    if (snake->lastDirection == Direction::up && snake->direction != Direction::down)
    {
        snake->direction = snake->lastDirection;
    }
    else if( snake->lastDirection == Direction::down && snake->direction != Direction::up){
        snake->direction = snake->lastDirection;
    }
    else if( snake->lastDirection == Direction::left && snake->direction != Direction::right){
        snake->direction = snake->lastDirection;
    }
    else if( snake->lastDirection == Direction::right && snake->direction != Direction::left){
        snake->direction = snake->lastDirection;
    }
}


void Logic::drawTicTacToe(TicTacToe *ticTacToe, Matrix &matrix){
    for (uint8_t i = 0; i < TICTACTOE_WIDTH; i++){
        for(uint8_t j = 0; j < TICTACTOE_HEIGHT; j++){
            uint8_t owner = ticTacToe->board[i][j];
            if(owner == Select::player1){
                Logic::drawField(i, j, Colors::red, matrix);
            }
            else if(owner == Select::player2){
                Logic::drawField(i, j, Colors::green, matrix);
            }
        }
    }
    Logic::drawBoardLines();
}

void Logic::drawField(uint8_t x, uint8_t y, Colors color ,Matrix &matrix){
    x = Logic::getPrepareValueForField(x);
    y = Logic::getPrepareValueForField(y);
    Rect rect = avrGame::rect(x, y, 2, 2);
    avrGame::draw.rect(matrix, rect, color);

    
}

uint8_t Logic::getPrepareValueForField(uint8_t value){
    uint8_t result = 0;
    switch(value){
        case 0:
            result = 1;
            break;
        case 1:
            result = 4;
            break;
        case 2:
            result = 7;
            break;
        default:
            result = 0;
        break;
    }
    return result;
}

void Logic::drawBoardLines(){
    uint8_t tab[2] = {3, 6};
    Rect rect = avrGame::rect(0, 0, 1, 1);
    for (uint8_t i = 0; i < 2; i++){
        rect = avrGame::rect(tab[i], 1, 1, 8);
        avrGame::draw.rect(avrGame::_matrix, rect, Colors::yellow);
        rect = avrGame::rect(1, tab[i], 8, 1);
        avrGame::draw.rect(avrGame::_matrix, rect, Colors::yellow);
    }
}