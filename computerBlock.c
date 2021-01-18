#include "ticTacToe.h"

int computerBlock( char board[ROWS][COLUMNS], int computerMove[2] ) {

    int i, j;
    char player1Symbol = 'X';
    char computerSymbol = 'O';
    int player1Count = 0;
    int blockRow;
    int blockCol;
    int freeSpace = 0;

    /* Checking rows for position to play block */ 
    for( i = 0; i < ROWS; ++i ) {
        printf( "In row check\n" );
        player1Count = 0;
        freeSpace = 0;

        for( j = 0; j < COLUMNS; ++j ) {

            if( board[i][j] == player1Symbol ) {
                player1Count += 1;
            }

            if( (board[i][j] != player1Symbol) && (board[i][j] != computerSymbol) ) {
                freeSpace = 1;
                blockCol = j;
            }
        }

        if( (player1Count == 2) && (freeSpace == 1) ) {

            computerMove[0] = i; 
            computerMove[1] = blockCol;
            return 1;
        }
    }

    /* Checking columns for position to play block */
    for( j = 0; j < COLUMNS; ++j ) {
        printf( "In column check\n" );
        player1Count = 0;
        freeSpace = 0;

        for( i = 0; i < ROWS; ++i ) {

            if( board[i][j] == player1Symbol ) {
                player1Count += 1;
            }

            if( (board[i][j] != computerSymbol) && (board[i][j] != player1Symbol) ) {
                freeSpace = 1;
                blockRow = i;
            }
        }

        if( (player1Count == 2) && (freeSpace == 1) ) {
            computerMove[0] = blockRow;
            computerMove[1] = j;
            return 1;
        }
    }

    i = 0;
    j = 0;
    player1Count = 0;
    freeSpace = 0;

    /* checking left diagonal for block position */
    while( (i <= 2) && (j <= 2) ) {
        printf( "In left diagonal check\n" );
        
        if( board[i][j] == computerSymbol ) {
            return 0;                               /* computer cannot block in diagonal */
        }

        if( board[i][j] == player1Symbol ) {
            player1Count += 1;
        }

        if( (board[i][j] != player1Symbol) && (board[i][j] != computerSymbol) ) {
            freeSpace = 1;
            blockRow = i;
            blockCol = j;
        }

        if( (player1Count == 2) && (freeSpace == 1) ) {

            computerMove[0] = blockRow;
            computerMove[1] = blockCol;
            return 1;
        }

        ++i;
        ++j;
    }

    i = 0;
    j = 2;
    player1Count = 0;
    freeSpace = 0;

    /* checking right diagonal for block position */
    while( (i <= 2) && (j >= 0) ) {
        printf( "In right diagonal check\n" );
        
        if( board[i][j] == computerSymbol ) {
            return 0;                               /* Computer cannot block in the diagonal */

        if( board[i][j] == player1Symbol ) {
            player1Count += 1;
        }

        if( (board[i][j] != player1Symbol) && (board[i][j] != computerSymbol) ) {
            freeSpace = 1;
            blockRow = i;
            blockCol = j;
        }

        if( (player1Count == 2) && (freeSpace == 1) ) {

            computerMove[0] = blockRow;
            computerMove[1] = blockCol;
            return 1;
        }

        ++i;
        --j;       
    }

    return 0;
}