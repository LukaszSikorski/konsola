#include "TicTacToe.h"

TicTacToe::TicTacToe(){
    clear();
}


void TicTacToe::clear(){
    for(uint8_t i = 0; i < TICTACTOE_WIDTH; i++){
        for(uint8_t j = 0; j < TICTACTOE_HEIGHT; j++){
            this->board[i][j] = Select::empty;
        }
    }
    this->board[0][1] = Select::player1;
    this->board[2][0] = Select::player2;
}

