#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ticTacToe.h"


/* User defined function declarations */

int main( int argc, char *argv[] ) {

    char newBoard[ROWS][COLUMNS] = { '1', '2', '3',
                                 '4', '5', '6',
                                 '7', '8', '9'};

    int playerOneMove;
    int playerTwoMove;
    int usedSpots[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; /* stores the positions that have already been played */
    int player = 0; /* Current turn is playerOne if 0 and playerTwo if 1 */
    int plays = 1;
    int winner = -1;
    int i;
    int j;
    int gameMode;
    int boardVal;
    int computerMove[2];

    printf( "Hello! Would you like to play against the computer or with another player?\n" );
    printf( "Enter 0 to play with two players or 1 to play against the computer: " );
    fscanf( stdin, "%d", &gameMode );

    /* Main loop that controls when to stop the game */    
    while( (plays < 10) && (gameMode == 0) && (winner == -1) ) { 
        
        player = 0;
        
        if( (plays % 2) == 0) {
            player = 1;
        }

        if( player == 0 ) {
        
            displayGameNew( newBoard );
            printf( "\n\nPlayer %d, enter position to play (1-9): ", player );
            fscanf( stdin, "%d", &playerOneMove );

            /* Checks for invalid plays */
            while( (playerOneMove < 1) || (playerOneMove > 9) ) {

                printf( "Error, player entered a number that was not between 1 and 9;\n please enter a new number: " );
                fscanf( stdin, "%d", &playerOneMove);
            }

            while( usedSpots[playerOneMove - 1] != 0 ) {

                printf( "Error, that position has already been played. Please select another position: " );
                fscanf( stdin, "%d", &playerOneMove );
            }

            usedSpots[playerOneMove - 1] = playerOneMove;
        
            for( i = 0; i < ROWS; ++i ) {
                for( j = 0; j < COLUMNS; ++j ) {
                    
                    boardVal = newBoard[i][j] - '0';
                    
                    if( boardVal == playerOneMove ) {
                        
                        newBoard[i][j] = 'X';
                    }        
                }
            }

            displayGameNew( newBoard );
        }

        if( player == 1 ) {
            
            displayGameNew( newBoard );
            printf( "\n\nPlayer %d, enter position to play (1-9): ", player );
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
            
            for( i = 0; i < ROWS; ++i ) {
                for( j = 0; j < COLUMNS; ++j ) {
                    
                    boardVal = newBoard[i][j] - '0';

                    if( boardVal == playerTwoMove ) {
                        
                        newBoard[i][j] = 'O';
                    }
                }
            }
            
            displayGameNew( newBoard );
        }


        winner = checkWin( newBoard, player );
        ++plays;
    }


    if( winner == 0 ) {
        printf( "\n\nplayer1 has won the game!\n" );
        return 1;
    }

    if( winner == 1 ) {
        printf( "\n\nPlayer2 has won the game!\n" );
        return 2;
    }

    printf( "\n\nGame over. Game was a draw!\n\n" );
                                  


   return 0;
}