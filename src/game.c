#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/board.h"
#include "../include/pieces.h"

char input[50];
bool game = true;
bool playerToMove = false; // False - white / True - black
char lastMove[6]; // 0=Piece 1=OldCol 2=OldRow 3=x||null 4=NewCol 5=NewRow
bool pieceCaptured = false;
bool moved = false;

void changePlayer() {
    if (playerToMove) {
        playerToMove = false;
    } else {
        playerToMove = true;
    }
}

int transformCharNum(const char character) {
    char result;
    switch (character) {
        case 'A':
        case 'a':
            result = 0;
            break;
        case 'B':
        case 'b':
            result = 1;
            break;
        case 'C':
        case 'c':
            result = 2;
            break;
        case 'D':
        case 'd':
            result = 3;
            break;
        case 'E':
        case 'e':
            result = 4;
            break;
        case 'F':
        case 'f':
            result = 5;
            break;
        case 'G':
        case 'g':
            result = 6;
            break;
        case 'H':
        case 'h':
            result = 7;
            break;
        default:
            printf("Invalid input\n");
            return false;
    }
    return result;
}

void movePiece(char origin[3], char destination[3]) {
    moved = false;
    pieceCaptured = false;
    const char (*b)[SIZE] = getBoard();

    const int originCol = transformCharNum(origin[0]);   // Col (a-h → 0–7)
    const int originRow = origin[1] - '1';               // Row (1–8 → 0–7)
    const int destinationCol = transformCharNum(destination[0]);
    const int destinationRow = destination[1] - '1';

    const char pieceToMove = b[originRow][originCol];

    if (pieceToMove == 'R' || pieceToMove == 'r') {
        moved = isValidRookMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
    }  else if (pieceToMove == 'B' || pieceToMove == 'b') {
        moved = isValidBishopMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
    } else if (pieceToMove == 'N'|| pieceToMove == 'n') {
        moved = isValidKnightMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
    } else if (pieceToMove == 'P' || pieceToMove == 'p') {
        moved = isValidPawnMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
    } else if (pieceToMove == 'Q' || pieceToMove == 'q') {
        moved = isValidQueenMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
    } else if (pieceToMove == 'K' || pieceToMove == 'k') {
        moved = isValidKingMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
    }
    // write last move
    lastMove[0] = pieceToMove;
    lastMove[1] = originCol;
    lastMove[2] = originRow;
    if (pieceCaptured) {
        lastMove[3] = 'x';
    } else {
        lastMove[3] = ' ';
    }
    lastMove[4] = destinationCol;
    lastMove[5] = destinationRow;

    if (moved) {
        changePlayer();
    } else if (!moved) {
        printf("Invalid move: Try again\n");
        system("pause");
    }
}

bool isGameOver() {
    return game;
}

void getCommand() {
    scanf("%99s", input);
    printBoard();
    if (strcmp(input, "end") == 0) {
        game = false;
    } else if (strcmp(input, "move") == 0) {
        printf("Which pice?(Enter Coordinates)");
        char piceOrigin[3];
        char piceDestination[3];
        scanf("%99s", piceOrigin);
        printf("To which square?");
        scanf("%99s", piceDestination);
        printBoard();
        if (((piceOrigin[0] >= 'a' && piceOrigin[0] <= 'h') ||
             (piceOrigin[0] >= 'A' && piceOrigin[0] <= 'H')) &&
            (piceOrigin[1] >= '1' && piceOrigin[1] <= '8') &&
            ((piceDestination[0] >= 'a' && piceDestination[0] <= 'h') ||
             (piceDestination[0] >= 'A' && piceDestination[0] <= 'H')) &&
            (piceDestination[1] >= '1' && piceDestination[1] <= '8')) {
            movePiece(piceOrigin, piceDestination);
        } else {
            printf("Invalid input\n");
            system("pause");
        }

    } else {
        printBoard();
        printf("This is not a command try again");
        system("pause");
        getCommand();
    }
}

bool getPlayerToMove() {
    return playerToMove;
}

char* getLastMove() {
    return lastMove;
}