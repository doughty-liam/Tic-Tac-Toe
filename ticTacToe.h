#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROWS 3
#define COLUMNS 3


int displayGameNew( char newBoard[ROWS][COLUMNS] );
int checkWin( char newBoard[ROWS][COLUMNS], int player ); 
int computerWinningPlay( char newBoard[ROWS][COLUMNS], int computerMove[2] );
int computerBlock( );
int computerRandom();