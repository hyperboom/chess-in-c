//
// Created by pauld on 18.09.2025.
//
#include <stdlib.h>
#include <stdio.h>

#define SIZE 8


int whitePawnState[SIZE] = {};
int blackPawnState[SIZE] = {};
char board[SIZE][SIZE] = {};

void clearScreen() {
    #ifdef _WIN32
        system("cls");
        system("color a");
    #else
        system("clear");
    #endif
}


void initBoard() {
    // pawn states
    for (int i = 0; i < 8;i++) {
        whitePawnState[i] = 0;
        blackPawnState[i] = 0;
    }
    // pawns
    for (int i = 0; i < 8; i++) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }
    // leere Felder
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = '.';
        }
    }
    // Rooks
    board[0][0] = 'R';
    board[0][7] = 'R';
    board[7][0] = 'r';
    board[7][7] = 'r';
    // Bishops
    board[0][2] = 'B';
    board[0][5] = 'B';
    board[7][2] = 'b';
    board[7][5] = 'b';
    // Horses
    board[0][1] = 'N';
    board[0][6] = 'N';
    board[7][1] = 'n';
    board[7][6] = 'n';
    // Queens
    board[0][3] = 'Q';
    board[7][3] = 'q';
    // Kings
    board[0][4] = 'K';
    board[7][4] = 'k';
}

/*
        A   B   C   D   E   F   G   H
      |-------------------------------|
    1 | R | N | B | Q | K | B | N | R |
      |-------------------------------|
    2 | P | P | P | P | P | P | P | P |
      |-------------------------------|
    3 |   |   |   |   |   |   |   |   |
      |-------------------------------|
    4 |   |   |   |   |   |   |   |   |
      |-------------------------------|
    5 |   |   |   |   |   |   |   |   |
      |-------------------------------|
    6 |   |   |   |   |   |   |   |   |
      |-------------------------------|
    7 | p | p | p | p | p | p | p | p |
      |-------------------------------|
    8 | r | n | b | q | k | b | n | r |
      |-------------------------------|
*/

void printBoard() {
    clearScreen();
    printf("    A   B   C   D   E   F   G   H \n");
    printf("  |-------------------------------|\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != '.') {
                printf("| %c ", board[i][j]);
            } else {
                printf("|   ");
            }
        }
        printf("|\n  |-------------------------------|\n");
    }
}

char (*getBoard())[SIZE] {  // Rückgabe: Pointer auf Array von SIZE chars
    return board;            // board „verfällt“ automatisch zu Pointer auf erstes Array
}

int* getWhitePawnState() {
    return whitePawnState;
}

int* getBlackPawnState() {
    return blackPawnState;
}