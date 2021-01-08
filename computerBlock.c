#include <stdio.h>
#include <stdlib.h>
#include "ticTacToe.h"


/*  

NOTE: Computer move array will store position of computer move in row, column form 
    
returns 1 if computer is able to block player1 and 0 if unable to. 
    
*/

int computerBlock( char newBoard[ROWS][COLUMNS], int computerMove[2] ) {

    int i, j;
    int colInd; /* holds index of block column */
    int rowInd; /* Holds index of block row */  
    char player1Symbol = 'X';
    char computerSymbol = 'O';
    int player1Count = 0;
    int computerCount = 0;
    int blockRow;
    int blockCol;
    int freeSpace = 0;


    /* Checking rows for position to play block */ 
    for( i = 0; i < ROWS; ++i ) {
        printf( "In row check\n" );
        player1Count = 0;
        computerCount = 0;

        for( j = 0; j < COLUMNS; ++j ) {

            if( newBoard[i][j] == player1Symbol ) {
                player1Count += 1;
            }

            if( newBoard[i][j] == computerSymbol ) {
                computerCount += 1;
            }

        }

        if( (player1Count == 2) && (computerCount == 0) ) {

            computerMove[0] = i; /* row to play block */
            
            for( colInd = 0; colInd < COLUMNS; ++colInd ) {

                if( newBoard[computerMove[0]][colInd] != player1Symbol ) {
                    
                    computerMove[1] = colInd;
                    return 1;
                }
            }
        }

    }



    /* Checking columns for position to play block */
    for( j = 0; j < COLUMNS; ++j ) {
        printf( "In column check\n" );
        player1Count = 0;
        computerCount = 0;

        for( i = 0; i < ROWS; ++i ) {

            if( newBoard[i][j] == player1Symbol ) {
                player1Count += 1;
            }

            if( newBoard[i][j] == computerSymbol ) {
                computerCount += 1;
            }

        }

        if( (player1Count == 2) && (computerCount == 0) ) {
            computerMove[1] = j;

            for( rowInd = 0; rowInd < ROWS; ++rowInd ) {

                if( newBoard[rowInd][computerMove[1]] != player1Symbol ) {

                    computerMove[0] = rowInd;
                    return 1;

                }
            } 
        }

    }

    i = 0;
    j = 0;
    player1Count = 0;
    computerCount = 0;

    /* checking left diagonal for block position */
    while( (i <= 2) && (j <= 2) ) {
        printf( "In left diagonal check\n" );
        if( newBoard[i][j] == computerSymbol ) {
            return 0;                               /* function cannot block if the computer already has
                                                       played position in the diagonal */    
        }

        if( newBoard[i][j] == player1Symbol ) {
            player1Count += 1;
        }

        if( newBoard[i][j] != player1Symbol ) {
            blockRow = i;
            blockCol = j;
            freeSpace = 1;
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
    computerCount = 0;
    freeSpace = 0;

    /* checking right diagonal for block position */
    while( (i <= 2) && (j >= 0) ) {
        printf( "In right diagonal check\n" );
        if( newBoard[i][j] == computerSymbol ) {
            return 0;                               /* function cannot block if the computer already has
                                                       played position in the diagonal */    
        }

        if( newBoard[i][j] == player1Symbol ) {
            player1Count += 1;
        }

        if( newBoard[i][j] != player1Symbol ) {
            blockRow = i;
            blockCol = j;
            freeSpace = 1;
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