//
// Created by pauld on 19.09.2025.
//

#ifndef SCHACH_IN_C_PIECES_H
#define SCHACH_IN_C_PIECES_H

void isValidRookMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
void isValidKnightMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
void isValidBishopMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
void isValidKingMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
void isValidPawnMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
void isValidQueenMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);

#endif //SCHACH_IN_C_PIECES_H