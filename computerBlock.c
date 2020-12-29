#include <stdio.h>
#include <stdlib.h>
#include "ticTacToe.h"

int computerMove( char newBoard[ROWS][COLUMNS], int computerMove[2] ) {

    int i, j;
    int colInd; /* holds index of block column */ 
    char player1Symbol = 'X';
    char computerSymbol = 'O';
    int player1Count = 0;
    int computerCount = 0;


    /* Checking rows for position to play block */ 
    for( i = 0; i < ROWS; ++i ) {
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
    






}