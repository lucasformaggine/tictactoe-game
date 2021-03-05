#include "board.h"
#include "pvp.h"
#include "pvc.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

char Board::board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'},
};

void Board::RunGame() {
    bool run = true;
    bool gameMode;

    while (run) {
        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "Player 1: X" << endl;
        cout << "Player 2: O" << endl;
        cout << "//////////////" << endl;
        cout << endl;

        int positionCounter = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                positionCounter++;
                cout << positionCounter << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Choose your game mode:" << endl;
        cout << "(1) Player vs Player (PvP)" << endl;
        cout << "(0) Player vs Computer (PvC)" << endl;

        cin >> gameMode;

        if (gameMode == 1) {
            PvP pvpGame;
            pvpGame.PlayPvPMode();
        } else {
            PvC pvcGame;
            pvcGame.PlayPvCMode();
        }

        cout << "Do you want to play again ? " << endl;
        cout << "(1) Yes" << endl;
        cout << "(0) No" << endl;

        cin >> run;
    }
}

void Board::PrintGame() {
    cout << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Board::board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int Board::CheckRowAndColumn() {
    int xRow = 0, oRow = 0;
    int xColumn = 0, oColumn = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board::board[i][j] == 'X') {
                xRow++;
            }
            else if (Board::board[i][j] == 'O') {
                oRow++;
            }

            if (Board::board[j][i] == 'X') {
                xColumn++;
            } else if (Board::board[j][i] == 'O') {
                oColumn++;
            }
        }

        if (xRow == 3 || xColumn == 3) {
            return 1;
        } else if (oRow == 3 || oColumn == 3) {
            return -1;
        } else {
            xRow = 0;
            xColumn = 0;
            oRow = 0;
            oColumn = 0;
        }
    }
    return 0;
}

int Board::CheckPrimaryCorner() {
    int xCorner = 0, oCorner = 0;

    for (int j = 0; j < 3; j++) {
        if (Board::board[j][j] == 'X') {
            xCorner++;
        } else if (Board::board[j][j] == 'O') {
            oCorner++;
        }
    }
    if (xCorner == 3) {
        return 1;
    } else if (oCorner == 3) {
        return -1;
    } else {
        xCorner = 0;
        oCorner = 0;
    }

    return 0;
}

int Board::CheckSecondaryCorner() {
    int xCorner = 0, oCorner = 0;

    for (int j = 2; j >= 0; j--) {
        if (Board::board[2 - j][j] == 'X') {
            xCorner++;
        } else if (Board::board[2 - j][j] == 'O') {
            oCorner++;
        }
    }
    if (xCorner == 3) {
        return 1;
    } else if (oCorner == 3) {
        return -1;
    } else {
        xCorner = 0;
        oCorner = 0;
    }

    return 0;
}

int Board::GetWinner() {
    if (Board::CheckRowAndColumn() == 1 || Board::CheckPrimaryCorner() == 1 || Board::CheckSecondaryCorner() == 1) {
        return 1; // Player 1 won
    } else if (Board::CheckRowAndColumn() == -1 || Board::CheckPrimaryCorner() == -1 || Board::CheckSecondaryCorner() == -1) {
        return -1; // Player 2 won
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (Board::board[i][j] == '-') {
                    return 2; // The game is not over.
                }
            }
        }
    }
    return 0; // Tie.
}

bool Board::Tie() {
    if (GetWinner() == 0) {
        return true;
    } else {
        return false;
    }
}

bool Board::GameOver() {
    if (Board::GetWinner() == 2) {
        return false;
    } else {
        return true;
    }
}

void Board::ClearGame() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Board::board[i][j] = '-';
        }
    }
}