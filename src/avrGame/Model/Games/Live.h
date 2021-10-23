#ifndef _LIVE_H
#define _LIVE_H

#include "Snake.h"
#include "../../avrGame.h"


class Live{
    public:
        Live();
        Live(const uint8_t cycle);
        Chunk *getChunk();
        Live *setChunk(const Chunk *chunk);
        void setCycle(const int8_t);
        bool isCycleZero();
        bool isCycleEqual(const int8_t);
        bool operator==(const Chunk *);
        Live *operator--(void);
        Chunk chunk;
    private:
        bool active;
        int8_t cycle;

};



#include <avr/io.h>

#endif