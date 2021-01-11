#include "board.h"
#include "pvc.h"
#include <iostream>

using namespace std;

void PvC::PlayPvCMode() {
    int decision;
    char player;
    bool isComputerTurn;

    cout << "Choose the starter player: " << endl;
    cout << "(1) Human (X)" << endl;
    cout << "(2) Computer (O)" << endl;
    cin >> decision;

    if (decision == 1) {
        player = 'X';
        isComputerTurn = false;
    } else if (decision == 2) {
        player = 'O';
        isComputerTurn = true;
    }

    while (GameOver() == false) {
        if (isComputerTurn == true) {
            cout << "Computer turn" << endl;

            PrintGame();
            ComputerTurn(player);
            PrintGame();

            player = AlternatePlayer(player);

            isComputerTurn = false;
        } else if (isComputerTurn == false) {
            cout << "Human turn" << endl;

            PrintGame();
            PlayerTurn(player);
            PrintGame();

            player = AlternatePlayer(player);

            isComputerTurn = true;
        }
    }

    if (Tie()) {
        cout << "Tie!" << endl;
    } else {
        PrintWinner();
    }

    ClearGame();
}

void PvC::PlayerTurn(char player) {
    int choice;

    while (1) {
        cout << "Select a position(1-9): " << endl;
        cin >> choice;

        if (board[(choice - 1) / 3][(choice - 1) % 3] == '-') {
            board[(choice - 1) / 3][(choice - 1) % 3] = player;
            break;
        } else {
            cout << "This position has already been chosen or is not in the board!" << endl;
        }
    }
}

void PvC::ComputerTurn(char player) {
    int bestScore = +2;
    int score;
    int best_i, best_j;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {

                board[i][j] = 'O';
                score = minimax(board, 'X', true); // The computer is "minimizing", but the next level is a max level.
                board[i][j] = '-';

                if (score < bestScore) {
                    bestScore = score;
                    best_i = i;
                    best_j = j;
                }

            }
        }
    }

    board[best_i][best_j] = 'O';
}

char PvC::AlternatePlayer(char player) {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }

    return player;
}

int PvC::minimax(char board[3][3], char player, bool isMaxLevel) {
    int bestScore;
    int score;
    int result = GetWinner();

    if (GameOver() == true) {
        return result;
    }

    if (isMaxLevel == true) { // Max Level
        bestScore = -2; // -Infinity

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {

                    board[i][j] = 'X';
                    score = minimax(board, 'O', false); // If this level is "maximizing", the next level is "minimizing".
                    board[i][j] = '-';

                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;

    } else if (isMaxLevel == false) { // Min Level
        bestScore = +2; // + Infinity

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {

                    board[i][j] = 'O';
                    score = minimax(board, 'X', true); // If this level is "minimizing", the next level is "maximizing".
                    board[i][j] = '-';

                    bestScore = min(score, bestScore);
                } 
            }
        }
        return bestScore;
    }

    return bestScore;
}

int PvC::max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int PvC::min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

void PvC::PrintWinner() {
    if (GetWinner() == 1) {
        cout << "Human won !" << endl << endl;
    } else if (GetWinner() == -1) {
        cout << "Computer won !" << endl << endl;
    }
}