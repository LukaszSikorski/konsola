#ifndef _TICTACTOE_H
#define _TICTACTOE_H
#include <avr/io.h>

#define TICTACTOE_WIDTH 3
#define TICTACTOE_HEIGHT 3

namespace Select{
    enum Select{
        empty,
        player1,
        player2
    };
}

class TicTacToe{
    public:
        TicTacToe();
        uint8_t board[TICTACTOE_WIDTH][TICTACTOE_HEIGHT];
        void init(void);

    private:
        void clear();
};

#endif
