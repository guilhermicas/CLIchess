#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "board.h"
#include "piece/piece.h"

#include "../shared.h"

//Colors used in printing the board
//Background Colors
#define ANSI_BG_WHITE      "\e[107m"
#define ANSI_BG_BLACK      "\e[40m"

//Foreground Colors
#define ANSI_FG_BLACK      "\e[34m"
#define ANSI_FG_WHITE      "\e[93m"

//Reset color
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
   resetBoard
   movePiece
   renderBoard
   checkCheck
   checkCheckMate
*/

void resetBoard(Piece *board){
  /*
  @*board Game Board

  @brief
    Resets the game pieces to:
            RNBQKBNR
            PPPPPPPP
                    
                    
                    
                    
            PPPPPPPP
            RNBQKBNR
  */

  //Black pieces
  board[0] = (Piece){.designation = 'R', .color = BLACK};
  board[1] = (Piece){.designation = 'N', .color = BLACK};
  board[2] = (Piece){.designation = 'B', .color = BLACK};
  board[3] = (Piece){.designation = 'Q', .color = BLACK};
  board[4] = (Piece){.designation = 'K', .color = BLACK};
  board[5] = (Piece){.designation = 'B', .color = BLACK};
  board[6] = (Piece){.designation = 'N', .color = BLACK};
  board[7] = (Piece){.designation = 'R', .color = BLACK};

  //Black Pawns
  for(int i = 8; i <= 15; i++)
    board[i] = (Piece){.designation = 'P', .color = BLACK};

  //Blank Pieces
  for (int i = 16; i < 48; i++)
    board[i] = (Piece){.designation = ' ', .color = NO_PIECE_COLOR};

  //White pieces
  board[56] = (Piece){.designation = 'R', .color = WHITE};
  board[57] = (Piece){.designation = 'N', .color = WHITE};
  board[58] = (Piece){.designation = 'B', .color = WHITE};
  board[59] = (Piece){.designation = 'Q', .color = WHITE};
  board[60] = (Piece){.designation = 'K', .color = WHITE};
  board[61] = (Piece){.designation = 'B', .color = WHITE};
  board[62] = (Piece){.designation = 'N', .color = WHITE};
  board[63] = (Piece){.designation = 'R', .color = WHITE};

  //White Pawns
  for(int i = 48; i <= 55; i++)
    board[i] = (Piece){.designation = 'P', .color = WHITE};
}

bool hasPiece(Piece *board, int idx){
  /*
    @*board Game Board
    @idx index of the board to check
    @return bool

    @brief
      Checks if there is a piece at the specified index position
  */

  if(idx > BOARD_SIZE || idx < 0)
    return false;

  return board[idx].designation == ' ' || board[idx].color == NO_PIECE_COLOR ? false : true;
}

//Prints the board to the screen
void renderBoard(Piece *board){
  system("clear");

  int rank = 8;

  for(int i = 0; i < 64; i+=8){
    printf("%d ", rank);

    for(int j = 0; j < 8; j++){
      Piece currPiece = board[i+j];

      //Alternates the colors, uses the rank to check for new line to alternate the colors again for checkered look
      if((j + rank % 2) % 2 == 0)
        printf(ANSI_BG_WHITE);
      else
        printf(ANSI_BG_BLACK);

      // If piece is black then \e[34m and if white \e[97m
      if(currPiece.color == BLACK)
        printf(ANSI_FG_BLACK);
      else
        printf(ANSI_FG_WHITE);


      printf(" %c ", currPiece.designation);
    }

    printf(ANSI_COLOR_RESET "\n");
    rank -= 1;

  }

  //Prints the Files
  printf("   a  b  c  d  e  f  g  h \n");
}

//resetBoard()

//MovePiece()

