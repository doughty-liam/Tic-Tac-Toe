#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROWS 7
#define COLUMNS 18

int displayGame( int board[ROWS][COLUMNS], int player ) {

    int i;
    int j;

    char *currentPlayer[2] = { "player 1", "player 2" };

    system( "clear" );

    printf( "\n" );
    printf( "Hello, welcome to Tic-Tac-Toe!\n" );
    printf( "To play a position on the board, enter the position number and press the return key.\n" );
    printf( "\nplayer 1: X\n" );
    printf( "player 2: O\n\n" );

    printf( "Current turn: %s\n\n", currentPlayer[player] );

    for( i = 0; i < 7; ++i ) {
        for( j = 0; j < 18; ++j) {
            
            printf( "%c", board[i][j] );
        }
    }

    printf( "\n" );
    printf( "%s select a position: ", currentPlayer[player] );

    return 0;
}