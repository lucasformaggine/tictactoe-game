#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
    static char board[3][3];
    void RunGame();
    void PrintGame();
    int CheckRowAndColumn();
    int CheckPrimaryCorner();
    int CheckSecondaryCorner();
    int GetWinner();
    bool Tie();
    bool GameOver();
    void ClearGame();
};

#endif