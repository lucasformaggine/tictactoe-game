# TicTacToe Game

A TicTacToe game made in C++ using minimax algorithm.

This is a TicTacToe game with two gamemodes: PvP (Player vs. Player) and PvC (Player vs. Computer). If you choose the second option, you'll be playing against a bot, that never loses.

This bot plays using the minimax algorithm: it tries all the possibilities of outcomes in each situation of the board; the situations that the computer wins are computed with a "min score" (and the human situations with a "max score"), so the computer chooses a play that minimize its scores and guarantees not to lose.

There are the following files in this game: pvp.cpp, pvc.cpp, board.cpp, main.cpp and the headers (pvp.h, pvc.h, board.h).

"Board" class contains codes based in the general game: print the board, clean the board, start the game etc.

"PvP" class contains codes based in the pvp mode: alternate the current player playing, player's move decision, the start of the pvp game itself etc.

"PvC" class contains codes based in the pvc mode: player's move decision, computer's turn, minimax algorithm, max and min functions etc.

Play the game using "main.cpp" file.
