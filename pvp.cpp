#include "board.h"
#include "pvp.h"
#include <iostream>

using namespace std;

void PvP::PlayPvPMode() {
    int decision;
    char player;

    cout << endl;
    cout << "Choose the starter player: " << endl;
    cout << "(1): Player 1 (X)" << endl;
    cout << "(2): Player 2 (O)" << endl;
    cin >> decision;

    if (decision == 1) {
        player = 'X';
    }
    else if (decision == 2) {
        player = 'O';
    }

    while (GameOver() == false) {
        cout << player << " turn." << endl << endl;

        PrintGame();
        PlayerTurn(player);
        PrintGame();

        player = AlternatePlayer(player);
    }

    if (Tie()) {
        cout << "Tie!" << endl;
    } else {
        PrintWinner();
    }

    ClearGame();
}

void PvP::PlayerTurn(char player) {
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

char PvP::AlternatePlayer(char player) {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }

    return player;
}

void PvP::PrintWinner() {
    if (GetWinner() == 1) {
        cout << "Player 1 won !" << endl << endl;
    } else if (GetWinner() == -1) {
        cout << "Player 2 won !" << endl << endl;
    }
}