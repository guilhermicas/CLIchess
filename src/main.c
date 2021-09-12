#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>

#include "board/board.h"
#include "board/piece/piece.h"

#include "shared.h"

//Game state flags
bool game_running = true;

//0 = White, 1 = Black
bool turn = WHITE;

int main(){
  // Board that stores all the pieces
  Piece board[64];

  //Main menu loop
  while(game_running){
    printf("Bem vindo a CLI chess.\nEscolha uma opcao abaixo.\n");
    printf("1. Jogar 1v1.\n");
    printf("2. Jogar 1vCPU.\n");

    //Game loop
    while(true){

      resetBoard(board);
      renderBoard(board);
      exit(0);

      //Get user input and print the piece at the location specified by user
      //Next: check if there any of the specified piece that are able to move to that position
      //Move loop, only exit if the move is valid
    }

  }

  return 0;
}

/*
 User move process:
  First validate the input syntactically:
    it should be something like:
      Piece->NewLocation
      or
      Piece->Location->NewLocation (this is explicit in the case of there being multiple pieces that can move to one location)

  If the position specified is on top of a piece, show the possible locations the piece can move
  Then check if the specified piece can move where it was specified:
    Is there a piece available to move to the specified location
    If there are multiple pieces that can move to the specified location, which one do you want to move

    It must follow the specific pieces movement convention
    It can only move if the king is not in check, or if the king is in check, the move must stop the king being in check.
    If the piece to move is the king, then check the relative squares that are not dangerous and it can move to those.
    If the king is in check, does the move protect the king to the point where it isnt in check anymore

  Checkmate:
    When the king doesnt have a move, and other pieces can t help the king
*/
