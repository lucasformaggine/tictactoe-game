#ifndef PVP_H
#define PVP_H

#include "board.h"

class PvP : Board {
public:
    void PlayPvPMode();
    void PlayerTurn(char player);
    char AlternatePlayer(char player);
    void PrintWinner();
};

#endif