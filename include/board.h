//
// Created by pauld on 18.09.2025.
//

#ifndef SCHACH_IN_C_BOARD_H
#define SCHACH_IN_C_BOARD_H
#define SIZE 8

void initBoard();
void printBoard();
char (*getBoard())[SIZE];
char (*getWhitePawnState())[SIZE];
char (*getBlackPawnState())[SIZE];

#endif //SCHACH_IN_C_BOARD_H