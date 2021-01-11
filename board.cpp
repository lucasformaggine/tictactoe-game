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
    bool gamemode;

    while (run) {
        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "Player 1: X" << endl;
        cout << "Player 2: O" << endl;
        cout << "//////////////" << endl;
        cout << endl;

        int c = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c++;
                cout << c << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Choose your game mode:" << endl;
        cout << "(1) Player vs Player (PvP)" << endl;
        cout << "(0) Player vs Computer (PvC)" << endl;

        cin >> gamemode;

        if (gamemode == 1) {
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
    int x_row = 0, o_row = 0;
    int x_column = 0, o_column = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board::board[i][j] == 'X') {
                x_row++;
            }
            else if (Board::board[i][j] == 'O') {
                o_row++;
            }

            if (Board::board[j][i] == 'X') {
                x_column++;
            } else if (Board::board[j][i] == 'O') {
                o_column++;
            }
        }

        if (x_row == 3 || x_column == 3) {
            return 1;
        } else if (o_row == 3 || o_column == 3) {
            return -1;
        } else {
            x_row = 0;
            x_column = 0;
            o_row = 0;
            o_column = 0;
        }
    }
    return 0;
}

int Board::CheckPrimaryCorner() {
    int x_corner = 0, o_corner = 0;

    for (int j = 0; j < 3; j++) {
        if (Board::board[j][j] == 'X') {
            x_corner++;
        } else if (Board::board[j][j] == 'O') {
            o_corner++;
        }
    }
    if (x_corner == 3) {
        return 1;
    } else if (o_corner == 3) {
        return -1;
    } else {
        x_corner = 0;
        o_corner = 0;
    }

    return 0;
}

int Board::CheckSecondaryCorner() {
    int x_corner = 0, o_corner = 0;

    for (int j = 2; j >= 0; j--) {
        if (Board::board[2 - j][j] == 'X') {
            x_corner++;
        } else if (Board::board[2 - j][j] == 'O') {
            o_corner++;
        }
    }
    if (x_corner == 3) {
        return 1;
    } else if (o_corner == 3) {
        return -1;
    } else {
        x_corner = 0;
        o_corner = 0;
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