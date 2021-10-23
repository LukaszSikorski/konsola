#ifndef _SNAKE_H
#define _SNAKE_H
#define SIZE_SNAKE 20

#include <avr/io.h>

class Chunk;
class Snake;

namespace Direction{
    enum Direction{
        stop,
        left,
        right,
        up,
        down
    };
}

class Memento{
    public:


};

class MementoChunk{
    public:
        MementoChunk(Chunk *chunk, uint8_t x, uint8_t y);
        MementoChunk();
        void restore();
        uint8_t getX();
        uint8_t getY();
    private:
        Chunk *chunk;
        uint8_t x:4;
        uint8_t y:4;

};

class MementoSnake{
    public:
        MementoSnake(Snake *snake, uint8_t lenght, int8_t lives, Chunk *chunks, Direction::Direction direction);
        MementoSnake();
        MementoChunk *getMementoChunk(uint8_t index);
        void restore();
        Direction::Direction direction;
        Snake *snake;
        uint8_t lenght:5;
        int8_t lives:3;
    private:
        MementoChunk chunks[SIZE_SNAKE];
        void createMemenotChunks(Chunk *chunks);

};


class Chunk{

    public:
        Chunk();
        Chunk(uint8_t x, uint8_t y);
        void clear();
        void move(uint8_t x, uint8_t y);
        void moveTo(const uint8_t x,const uint8_t y);
        void moveTo(Chunk *chunk);
        void setX(uint8_t x);
        void setY(uint8_t y);
        void show()const;
        uint8_t getX(void) const;
        uint8_t getY(void) const;
        bool operator==(const Chunk &chunk)const;
        bool operator!=(const Chunk &chunk)const;
        MementoChunk save();
        void restore(MementoChunk *);
    private:
        uint8_t x:4;
        uint8_t y:4;
};

class Snake{
    
    public:
        Snake(const uint8_t live = 2);
        MementoSnake save();
        void restore(MementoSnake *);
        void clear();
        uint8_t lenght:5;
        int8_t lives:3;
        Chunk chunks[SIZE_SNAKE];
        Direction::Direction direction;
        Direction::Direction lastDirection;


};




#endif //