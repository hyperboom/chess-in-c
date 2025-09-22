#include "include/board.h"
#include "include/game.h"


int main(void) {
    initBoard();
    printBoard();
    while (isGameOver()) {
        getCommand();
        printBoard();
    }
    return 0;
}