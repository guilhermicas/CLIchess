#include "piece/piece.h"

#ifndef _BOARD_H_
#define _BOARD_H_

void resetBoard();
bool hasPiece(Piece *board, int idx);
void renderBoard(Piece board[]);

#endif
