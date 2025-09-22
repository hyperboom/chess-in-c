//
// Created by pauld on 19.09.2025.
//
#include <stdio.h>
#include <stdlib.h>

#include "../include/board.h"
#include "../include/game.h"

void move(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove) {
    char (*b)[SIZE] = getBoard();
    b[originRow][originCol] = '.';
    b[destinationRow][destinationCol] = pieceToMove;
}

void isValidRookMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove) {
    char (*b)[SIZE] = getBoard();
    if (originCol == destinationCol) {
        for (int i = originRow + 1; i < SIZE; i++) {
            if (b[i][originCol] != '.') {
                printf("Invalid move for '%c'\n", pieceToMove);
                system("pause");
                return;
            }
            move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
            changePlayer();
        }
    } else if (originRow == destinationRow) {
        for (int i = originCol + 1; i < SIZE; i++) {
            if (b[i][originCol] != '.') {
                printf("Invalid move for '%c'\n", pieceToMove);
                system("pause");
                return;
            }
            move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
            changePlayer();
        }
    }
}

void isValidKnightMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove) {
    char (*b)[SIZE] = getBoard();

}

void isValidBishopMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove) {
    char (*b)[SIZE] = getBoard();

}

void isValidKingMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove) {
    char (*b)[SIZE] = getBoard();

}

void isValidPawnMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove) {
    char (*b)[SIZE] = getBoard();
    char (*wP)[SIZE] = getWhitePawnState();
    char (*wB)[SIZE] = getBlackPawnState();

}

void isValidQueenMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove) {
    char (*b)[SIZE] = getBoard();

}