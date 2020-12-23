#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 7
#define COLUMNS 18

/* 

Function return values: -1 = no winner
0 = player1 has won the game
1 = player2 has won the game

*/

int checkWin( char newBoard[ROWS][COLUMNS], int player ) {

    int i;
    int j;
    int rowCount = 0;
    int columnCount = 0;
    char playerSymbol;

    if( player == 0 ) {
        playerSymbol = 'X';
    }

    if( player == 1 ) {
        playerSymbol = 'O';
    }

        
        /* row check */
        for( i = 0; i < ROWS; ++i ) {
            
            if( rowCount == 3 ) {

                return player; 
            }
            
            rowCount = 0;

            for( j = 0; j < COLUMNS; ++j ) {

                if( newBoard[i][j] == playerSymbol ) {
                    
                    rowCount++;
                }    
            }
        }

        /* Column check */
        for( i = 0; i < COLUMNS; ++i ) {
            
            if( columnCount == 3 ) {
            
                return player;
            }

            columnCount = 0;
            
            for( j = 0; j < ROWS; ++j ) {

                if( newBoard[j][i] == playerSymbol ) {
                    
                    columnCount++;
                }
            }
        }

        /* diagonal checks */
        if(  ( (newBoard[0][0] == playerSymbol) && (newBoard[1][1] == playerSymbol) && (newBoard[2][2] == playerSymbol) )
           || ( (newBoard[0][2] == playerSymbol) && (newBoard[1][1] == playerSymbol) && (newBoard[2][0] == playerSymbol) )  ){
            
            return player;
        }
    
    
    return -1;
}