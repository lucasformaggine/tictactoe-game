# TicTacToe Game

A TicTacToe game made in C++ using minimax algorithm.

This is a TicTacToe game with two gamemodes: PvP (Player vs. Player) and PvC (Player vs. Computer). If you choose the second option, you'll be playing against a bot, that never loses.

This bot plays using the minimax algorithm: it tries all the possibilities of outcomes in each situation of the board; the situations that the computer wins are computed with a "min score" (and the human situations with a "max score"), so the computer chooses a play that minimize its scores and guarantees not to lose.
