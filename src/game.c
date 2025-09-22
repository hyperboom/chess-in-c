//
// Created by pauld on 18.09.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/board.h"
#include "../include/pieces.h"

char input[100];
bool game = true;
bool playerToMove = false; // False - white / True - black

void changePlayer() {
    if (playerToMove) {
        playerToMove = false;
    } else {
        playerToMove = true;
    }
}

int transformCharNum(char input) {
    char result;
    switch (input) {
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
    char (*b)[SIZE] = getBoard();

    int originCol = transformCharNum(origin[0]);   // Spalte (a-h → 0–7)
    int originRow = origin[1] - '1';               // Reihe (1–8 → 0–7)
    int destinationCol = transformCharNum(destination[0]);
    int destinationRow = destination[1] - '1';

    char pieceToMove = b[originRow][originCol];          // Zugriff: [zeile][spalte]

    if (playerToMove == false) {
        if (pieceToMove == 'R') {
            isValidRookMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        }  else if (pieceToMove == 'B') {
            isValidBishopMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        } else if (pieceToMove == 'N') {
            isValidKnightMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        } else if (pieceToMove == 'P') {
            isValidPawnMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        } else if (pieceToMove == 'Q') {
            isValidQueenMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        } else if (pieceToMove == 'K') {
            isValidKingMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        }
    } else if (playerToMove == true) {
        if (pieceToMove == 'r') {
            isValidRookMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        }  else if (pieceToMove == 'b') {
            isValidBishopMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        } else if (pieceToMove == 'n') {
            isValidKnightMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        } else if (pieceToMove == 'p') {
            isValidPawnMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        } else if (pieceToMove == 'q') {
            isValidQueenMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        } else if (pieceToMove == 'k') {
            isValidKingMove(originCol, originRow, destinationCol, destinationRow, pieceToMove);
        }
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