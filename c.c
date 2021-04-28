#include <stdio.h>
#include <stdbool.h> 

//Game Board (where the magic happens)
char board[] = "RNBQKBNRPPPPPPPP                                RNBQKBNRPPPPPPPP";
int board_size = (sizeof board) - 1;

//0 = White, 1 = Black
bool turn = 0;

void renderBoard(){
  for(int i = 0; i < board_size; i++){
    printf("%c",board[i]);

    if(((i+1) % 8) == 0){
      printf("\n");
    }
  }
}

int main(int argc, char **argv[]){
  renderBoard();

  return 1;
}

/*
Piece designation:
- K king
- Q queen
- R rook, castle
- B bishop
- N knight
- P pawn

Other designation:
- x - Piece got eaten

Visual design:
  Problably use some unicode
  Black on Top and White on bottom
Ideas:
  Maybe able to online multiplayer through sockets

Game options:
  Enable history rewriting:
    If enabled you are able to go undo moves and rewrite the future.
    If disabled you are able to go back in the history but you are unable to change the future.

  Show coordinates:
    shows the 12345678 and ABCDEFGH

History System:
  (Array || dict of chars)
  A turn will consist of a white turn and a black turn.
  for example:
    1. a3 e5
    2. a4 d5

  These were 2 full turns where a white pawn was moved to a3, and a black pawn was moved to e5

  History logging and reliving system:
    CCN = chess coordinate system obtained through converting newPiecePosition in Move function to CCN

    Log history with CCN at the end turn.

  History importing:
    So we can import external games and replay the history on them

    The legality of moves isnt checked, just assumes the history is right and plays the history up to the current move in the history log

  In the end of the game create a file with history log.

  History functions:
    undo():
      goes back by one in the history
      if a new move is made, the whole future of the history is wiped and you cant rewind that
      otherwise you can go forward in the future again
    redo():
      goes forward by one in the history
    goBack():
      goes back in the history but doesnt change the history
      enables a new option that goes 
    goBack():
      goes forward in the history

Game system:
  Functions we should have:
    renderBoard():
      it will use NCurses to properly render
      it will render based on the last move in history

    Functions to interchange between CCN and idx notation.
    IdxToCCN()
    CCNToIdx()

    endTurn():
      Verifications at the end of turns:
        Win verification:
          checkCheckMate():
            Should be run every turn to check if there was a check mate

        checkCheck():
          Check one of the kings is in check
      

    At the end of every game:
      printResult():
        checks the result and prints the winner or draw or resignation

      historyLog():
        creates a file with the history of the ended game

Move(newPosition(CCN notation)):
    newPosition is given inputed by the user

    Verifications:
      Check if the given piece is able to move to the new position:
        lets imagine Nc3, we need to scan the board and check if there is any Knight that is able move to c3

        Also we need to check if there is any piece there, if its an enemy piece we need to log the move with x, if there is friendly piece we cant move.

        Needs to check if the king is in check and what pieces can move to protect the king, else just the king can move, if the king is unable to move due to enemy then checkmate

        Needs to check if a pawn reached the last rank
*/