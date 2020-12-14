#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 7
#define COLUMNS 18

/* 

Function return values: 0 = no winner
1 = player1 has won the game
2 = player2 has won the game

*/

int checkWin( int gameGrid[ROWS][COLUMNS], int player ) {

    int i;
    int j;
    int rowCount = 0;
    int columnCount = 0;

    /* Player one*/
    if( player == 0 ) {
        
        /* row check */
        for( i = 0; i < 7; ++i ) {
            
            if( rowCount == 3 ) {

                return 1; 
            }
            
            rowCount = 0;

            for( j = 0; j < 18; ++j ) {

                if( gameGrid[i][j] == 88 ) {
                    
                    rowCount++;
                }    
            }
        }

        /* Column check */
        for( i = 0; i < 18; ++i ) {
            
            if( columnCount == 3 ) {
            
                return 1;
            }

            columnCount = 0;
            
            for( j = 0; j < 7; ++j ) {

                if( gameGrid[j][i] == 88 ) {
                    
                    columnCount++;
                }
            }
        }
        /* diagonal checks */
        if( (  (gameGrid[0][2] == 88) && (gameGrid[3][8] == 88) && (gameGrid[6][14] == 88) ) || ( (gameGrid[0][14] == 88) && (gameGrid[3][8] == 88) && (gameGrid[6][2] == 88) )  ){
            
            return 1;
        }
    }


    /* Player two */ 
    if( player == 1 ) {
        
        /* row check */
        for( i = 0; i < 7; ++i ) {
            
            if( rowCount == 3 ) {

                return 2; 
            }
            
            rowCount = 0;

            for( j = 0; j < 18; ++j ) {

                if( gameGrid[i][j] == 79 ) {
                    
                    rowCount++;
                }    
            }
        }

        /* Column check */
        for( i = 0; i < 18; ++i ) {
            
            if( columnCount == 3 ) {
            
                return 2;
            }

            columnCount = 0;
            
            for( j = 0; j < 7; ++j ) {

                if( gameGrid[j][i] == 79 ) {
                    
                    columnCount++;
                }
            }
        }

        /* diagonal checks */
        if( (  (gameGrid[0][2] == 79) && (gameGrid[3][8] == 79) && (gameGrid[6][14] == 79) ) || ( (gameGrid[0][14] == 79) && (gameGrid[3][8] == 79) && (gameGrid[6][2] == 79) )  ){
            
            return 2;
        }
    }

    
    return 0;
}