#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 3
#define COLUMNS 3

int displayGameNew( char boardNew[3][3] ) {

    system( "clear" );
    
    int i = 0;
    int j = 0;

    for( i = 0; i < ROWS; ++i ) {
        for( j = 0; j < COLUMNS; ++j ) {
            
            printf( " %c ", boardNew[i][j] );
            
            if( j < 2 ) {
                printf( "|" ); 
            }

        }

        printf( "\n" );
        
        if( i < 2 ) {
            printf( "-----------" );
            printf( "\n" );
        }
    }


    return 0;

}