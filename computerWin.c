#include "ticTacToe.h"

int computerWin( char board[ROWS][COLUMNS], int computerMove[2] ) {

    int i, j;
    int colIndex;
    int rowIndex;
    char player1Symbol = 'X';
    char computerSymbol = 'O';
    int computerCount;
    int winningRow;
    int winningColumn;
    int freeSpace = 0;

    /* checking rows for winning position */
    for( i = 0; i < ROWS; ++i ) {
        printf( "In row check\n" );
        computerCount = 0;
        freeSpace = 0;

        for( j = 0; j < COLUMNS; ++j ) {

            if( board[i][j] == computerSymbol ) {
                computerCount += 1;
            }

            if( (board[i][j] != computerSymbol) && (board[i][j] != player1Symbol) ) {
                freeSpace = 1;
                winningColumn = j;
            }    computerCount = 0;
        }

        if( (computerCount == 2) && (freeSpace == 1) ) {
            computerMove[0] = i;
            computerMove[1] = winningColumn;
            return 1;
        }
    }

    /* checking columns for winning position */
    for( j = 0; j < COLUMNS; ++j ) {
        printf( "In column check\n" );
        computerCount = 0;  
        freeSpace = 0;   
        
        for( i = 0; i < ROWS; ++i ) {

            if( board[i][j] == computerSymbol ) {
                computerCount += 1;
            }

            if( (board[i][j] != computerSymbol) && (board[i][j] != player1Symbol) ) {
                freeSpace = 1;
                winningRow = i;
            }
        }

        if( (computerCount == 2) && (freeSpace == 1) ) {
            computerMove[0] = winningRow;
            computerMove[1] = j;
            return 1;
        }
    }

    i = 0;
    j = 0;
    freeSpace = 0;
    computerCount = 0;

    /* Checking left diagonal for winning position */
    while( (i < 3) && (j < 3) ) {
        printf( "In left diagonal check\n" );

        if( board[i][j] == player1Symbol ) {
            return 0;                              /* Computer unable to win if player 1 has diagonal position */
        }
        
        if( board[i][j] == computerSymbol ) {
            computerCount += 1;
        }

        if( (board[i][j] != computerSymbol) && (board[i][j] != player1Symbol) ) {
            freeSpace = 1;
            winningRow = i;
            winningColumn = j;
        }

        if( (computerCount == 2) && (freeSpace == 1) ) {
            computerMove[0] = winningRow;
            computerMove[1] = winningColumn;
            return 1;
        }

        ++i;
        ++j;
    }

    i = 0;
    j = 2;
    freeSpace = 0;
    computerCount = 0;

    /* Checking left diagonal for winning position */
    while( (i <= 2) && (j >= 0) ) {
        printf( "In right diagonal check\n" );

        if( board[i][j] == player1Symbol ) {
            return 0;
        }

        if( board[i][j] == computerSymbol ) {
            computerCount += 1;
        }

        if( (board[i][j] != computerSymbol) && (board[i][j] != player1Symbol) ) {
            freeSpace = 1;
            winningRow = i;
            winningColumn = j;
        }

        if( (computerCount == 2) && (freeSpace == 1) ) {
            computerMove[0] = winningRow;
            computerMove[1] = winningColumn;
            return 1;
        }

        ++i;
        --j;
    } 

    return 0;
}