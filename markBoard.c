#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 7
#define COLUMNS 18


/* Function will take the desired position and the current player from main */
int markBoard( int playerPosition, int player ) {

    int gameGrid[ROWS][COLUMNS] = { 32, 32, 49, 32, 32, 124, 32, 32, 50, 32, 32, 124, 32, 32, 51, 32, 32, 10,
                                        95, 95, 95, 95, 95, 124, 95, 95, 95, 95, 95, 124, 95, 95, 95, 95, 95, 10,
                                        32, 32, 32, 32, 32, 124, 32, 32, 32, 32, 32, 124, 32, 32, 32, 32, 32, 10, 
                                        32, 32, 52, 32, 32, 124, 32, 32, 53, 32, 32, 124, 32, 32, 54, 32, 32, 10,
                                        95, 95, 95, 95, 95, 124, 95, 95, 95, 95, 95, 124, 95, 95, 95, 95, 95, 10, 
                                        32, 32, 32, 32, 32, 124, 32, 32, 32, 32, 32, 124, 32, 32, 32, 32, 32, 10,
                                        32, 32, 55, 32, 32, 124, 32, 32, 56, 32, 32, 124, 32, 32, 57, 32, 32, 10
                                      };
    int i;
    int j;

    for( i = 0; i < 7; ++i ) {
        for( j = 0; j < 18; ++j ) {
        
            if( gameGrid[i][j] == ( playerPosition + 48) ) {
                
                if( player == 0 ) {
                    gameGrid[i][j] = 88;    
                }
                
                if( player == 1 ) {
                    gameGrid[i][j] = 79;
                } 
            
            }
        }

    }








    return gameGrid;
}