#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/board.h"
#include "../include/game.h"

int knigthMoves[8][2] = {
    {+2,+1},
    {+2,-1},
    {-2,+1},
    {-2,-1},
    {+1,+2},
    {+1,-2},
    {-1,+2},
    {-1,-2}
};

void move(const int originCol,const int originRow,const int destinationCol,const int destinationRow,const char pieceToMove) {
    char (*b)[SIZE] = getBoard();
    if ((getPlayerToMove() && isupper(pieceToMove)) || !getPlayerToMove() && islower(pieceToMove)) {
        if (isupper(pieceToMove) && b[destinationCol][destinationRow] != '.' && islower(b[destinationCol][destinationRow])) {
            b[originRow][originCol] = '.';
            b[destinationRow][destinationCol] = pieceToMove;
        } else if (isupper(pieceToMove) && b[destinationCol][destinationRow] == '.') {
            b[originRow][originCol] = '.';
            b[destinationRow][destinationCol] = pieceToMove;
        } else if (islower(pieceToMove) && b[destinationCol][destinationRow] != '.' && isupper(b[destinationCol][destinationRow])) {
            b[originRow][originCol] = '.';
            b[destinationRow][destinationCol] = pieceToMove;
        } else if (islower(pieceToMove) && b[destinationCol][destinationRow] == '.') {
            b[originRow][originCol] = '.';
            b[destinationRow][destinationCol] = pieceToMove;
        } else {
            printf("Invalid piece to move\n");
            system("pause");
        }
    }
}

bool isValidRookMove(const int originCol, const int originRow, const int destinationCol, const int destinationRow, const char pieceToMove) {
    const char (*b)[SIZE] = getBoard();


    if (originCol != destinationCol && originRow != destinationRow) {
        printf("Invalid rook move for '%c'\n", pieceToMove);
        system("pause");
        return false;
    }


    if (originCol == destinationCol) {
        const int step = (destinationRow > originRow) ? 1 : -1;
        for (int r = originRow + step; r != destinationRow; r += step) {
            if (b[r][originCol] != '.') {
                printf("Path blocked for rook '%c'\n", pieceToMove);
                system("pause");
                return false;
            }
        }
    }


    if (originRow == destinationRow) {
        const int step = (destinationCol > originCol) ? 1 : -1;
        for (int c = originCol + step; c != destinationCol; c += step) {
            if (b[originRow][c] != '.') {
                printf("Path blocked for rook '%c'\n", pieceToMove);
                system("pause");
                return false;
            }
        }
    }


    move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
    printf("Valid rook move for '%c'\n", pieceToMove);
    return true;
}

bool isValidKnightMove(const int originCol, const int originRow, const int destinationCol, const int destinationRow, const char pieceToMove) {
    for (int i = 0; i < 8; i++) {
        const int tempCol = originCol + knigthMoves[i][0];
        const int tempRow = originRow + knigthMoves[i][1];
        if (destinationCol == tempCol && destinationRow == tempRow) {
            move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
            return true;
        }
    }
    printf("Invalid move for '%c'\n", pieceToMove);
    system("pause");
    return false;
}

bool isValidBishopMove(const int originCol, const int originRow, const int destinationCol, const int destinationRow, const char pieceToMove) {
    const char (*b)[SIZE] = getBoard();

    const int colDiff = destinationCol - originCol;
    const int rowDiff = destinationRow - originRow;

    // 1. diagonal cases check
    if (abs(colDiff) != abs(rowDiff) || (colDiff == 0 && rowDiff == 0)) {
        printf("Invalid bishop move for '%c'\n", pieceToMove);
        system("pause");
        return false;
    }

    // 2. calculates in which direction it has to go
    const int stepCol = (colDiff > 0) ? 1 : -1;
    const int stepRow = (rowDiff > 0) ? 1 : -1;

    // 3. checks all tiles between start and finish
    int c = originCol + stepCol;
    int r = originRow + stepRow;
    while (c != destinationCol && r != destinationRow) {
        if (b[r][c] != '.') {  // Annahme: '.' = leeres Feld
            printf("Path blocked for bishop '%c'\n", pieceToMove);
            system("pause");
            return false;
        }
        c += stepCol;
        r += stepRow;
    }
    if (b[destinationRow][destinationCol] == '.') {
        move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        return true;
    }
    if ((getPlayerToMove() && isupper(b[destinationRow][destinationCol])) || (!getPlayerToMove() && b[destinationRow][destinationCol])) {
            move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
            printf("Bishop '%c' captures!\n", pieceToMove);
            system("pause");
            return true;
    }
    printf("Invalid bishop move for '%c'\n", pieceToMove);
    system("pause");
    return false;
}

bool isValidKingMove(const int originCol, const int originRow, const int destinationCol, const int destinationRow, const char pieceToMove) {
    const int colDiff = destinationCol - originCol;
    const int rowDiff = destinationRow - originRow;

    if (colDiff >= -1 && colDiff <= 1 && rowDiff >= -1 && rowDiff <= 1 && !(colDiff == 0 && rowDiff == 0)) {
        move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        return true;
    }
    printf("Invalid move for '%c'\n", pieceToMove);
    system("pause");
    return false;
}

bool isValidPawnMove(const int originCol, const int originRow, const int destinationCol, const int destinationRow, const char pieceToMove) {
    char (*b)[SIZE] = getBoard();
    int* wP = getWhitePawnState();
    int* bP = getBlackPawnState();
    if (!getPlayerToMove()) {
        if (wP[originRow] == 0 && (originCol == destinationCol && originRow == destinationRow + 2)) {
            move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
            wP[originRow] = 1;
            return true;
        }
        if (((originCol == destinationCol + 1 && originRow == destinationRow + 1) || (originCol == destinationCol + 1 && originRow == destinationRow -1)) && b[destinationRow][originCol] != '.' && islower(b[destinationRow][originCol])) {
            move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
            return true;
        }
        // En passent ?
    } else {
        if (bP[originRow] == 0 && (originCol == destinationCol && originRow == destinationRow - 2)) {
            move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
            bP[originRow] = 1;
            return true;
        }
        if (((originCol == destinationCol - 1 && originRow == destinationRow + 1) || (originCol == destinationCol - 1 && originRow == destinationRow -1))  && b[destinationRow][originCol] != '.' && isupper(b[destinationRow][originCol])) {
            move(originCol, originRow, destinationCol, destinationRow, pieceToMove);
            return true;
        }
        // En passent ?
    }
    printf("Invalid move for '%c'\n", pieceToMove);
    system("pause");
    return false;
}

bool isValidQueenMove(const int originCol, const int originRow, const int destinationCol, const int destinationRow, const char pieceToMove) {
    if (isValidBishopMove(originCol, originRow, destinationCol, destinationRow, pieceToMove) || isValidRookMove(originCol, originRow, destinationCol, destinationRow, pieceToMove)) {
        return true;
    }
    printf("Invalid move for '%c'\n", pieceToMove);
    system("pause");
    return false;
}