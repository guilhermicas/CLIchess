#include <stdbool.h>

#ifndef _PIECE_H_
#define _PIECE_H_

//Piece class for each piece in the game board
typedef struct Pieces{
  char designation; // RNBQKP
  bool color; // BLACK || WHITE
} Piece;

#endif
