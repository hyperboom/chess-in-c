#ifndef SCHACH_IN_C_BOARD_H
#define SCHACH_IN_C_BOARD_H
#define SIZE 8

void initBoard();
void printBoard();
char (*getBoard())[SIZE];
int* getWhitePawnState();
int* getBlackPawnState();

#endif //SCHACH_IN_C_BOARD_H