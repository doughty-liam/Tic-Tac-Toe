#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ROWS 7
#define COLUMNS 18

/* User defined function declarations */
int checkWin( int gameGrid[ROWS][COLUMNS], int player );
int displayGame( int board[ROWS][COLUMNS], int player );


int main( int argc, char *argv[] ) {

    /* Stores the original playing board */
    int startingGrid[ROWS][COLUMNS] = { 32, 32, 49, 32, 32, 124, 32, 32, 50, 32, 32, 124, 32, 32, 51, 32, 32, 10,
                                        95, 95, 95, 95, 95, 124, 95, 95, 95, 95, 95, 124, 95, 95, 95, 95, 95, 10,
                                        32, 32, 32, 32, 32, 124, 32, 32, 32, 32, 32, 124, 32, 32, 32, 32, 32, 10, 
                                        32, 32, 52, 32, 32, 124, 32, 32, 53, 32, 32, 124, 32, 32, 54, 32, 32, 10,
                                        95, 95, 95, 95, 95, 124, 95, 95, 95, 95, 95, 124, 95, 95, 95, 95, 95, 10, 
                                        32, 32, 32, 32, 32, 124, 32, 32, 32, 32, 32, 124, 32, 32, 32, 32, 32, 10,
                                        32, 32, 55, 32, 32, 124, 32, 32, 56, 32, 32, 124, 32, 32, 57, 32, 32, 10
                                      };
    int playerOneMove;
    int playerTwoMove;
    int usedSpots[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; /* stores the positions that have already been played */
    int player = 0; /* Current turn is playerOne if 0 and playerTwo if 1 */
    int plays = 1;
    int winner;
    int i;
    int j;

    /* Main loop that controls when to stop the game */    
    while( (plays < 10) && ( checkWin(startingGrid, player) != 1 ) && ( checkWin(startingGrid, player) != 2 ) ) { 
        
        player = 0;
        
        if( (plays % 2) == 0) {
            player = 1;
        }

        if( player == 0 ) {
        
            displayGame( startingGrid, player );
            fscanf( stdin, "%d", &playerOneMove );

            /* Chekcks for invalid plays */
            while( (playerOneMove < 1) || (playerOneMove > 9) ) {

                printf( "Error, player entered a number that was not between 1 and 9;\n please enter a new number: " );
                fscanf( stdin, "%d", &playerOneMove);
            }

            while( usedSpots[playerOneMove - 1] != 0 ) {

                printf( "Error, that position has already been played. Please select another position: " );
                fscanf( stdin, "%d", &playerOneMove );
            }

            usedSpots[playerOneMove - 1] = playerOneMove;
        
            for( i = 0; i < 7; ++i ) {
                for( j = 0; j < 18; ++j ) {
            
                    if( startingGrid[i][j] == ( playerOneMove + 48) ) {
                        
                        startingGrid[i][j] = 88;
                    }        
                }
            }

            displayGame( startingGrid, player );
        }

        if( player == 1 ) {
            
            displayGame( startingGrid, player );
            fscanf( stdin, "%d", &playerTwoMove );

            while( (playerTwoMove < 1) || (playerTwoMove > 9) ) {

                printf( "Error, player entered a number that was not between 1 and 9;\n please enter a new number: " );
                fscanf( stdin, "%d", &playerTwoMove);
            }
            
            while( usedSpots[playerTwoMove - 1] != 0 ) {

                printf( "Error, that position has already been played. Please select another position: " );
                fscanf( stdin, "%d", &playerTwoMove );
            }

            usedSpots[playerTwoMove - 1] = playerTwoMove;
            
            for( i = 0; i < 7; ++i ) {
                for( j = 0; j < 18; ++j ) {
            
                    if( startingGrid[i][j] == ( playerTwoMove + 48) ) {
                        
                        startingGrid[i][j] = 79;
                    }
                }
            }
            
            displayGame( startingGrid, player );
        }

        winner = checkWin(startingGrid, player);
        ++plays;
    }


    if( winner == 1 ) {
        printf( "\n\nplayer1 has won the game!\n" );
        return 1;
    }

    if( winner == 2 ) {
        printf( "\n\nPlayer2 has won the game!\n" );
        return 2;
    }

    printf( "\n\nGame over. Game was a draw!\n\n" );
                                  


   return 0;
}