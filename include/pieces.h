#ifndef SCHACH_IN_C_PIECES_H
#define SCHACH_IN_C_PIECES_H

bool isValidRookMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
bool isValidKnightMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
bool isValidBishopMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
bool isValidKingMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
bool isValidPawnMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);
bool isValidQueenMove(int originCol, int originRow, int destinationCol, int destinationRow, char pieceToMove);

#endif //SCHACH_IN_C_PIECES_H