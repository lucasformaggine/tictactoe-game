#ifndef PVC_H
#define PVC_H

#include "board.h"

class PvC : Board {
    public:
        void PlayPvCMode();
        void PlayerTurn(char player);
        void ComputerTurn(char player);
        char AlternatePlayer(char player);
        int minimax(char board[3][3], char player, bool isMaxLevel);
        int max(int a, int b);
        int min(int a, int b);
        void PrintWinner();
};

#endif