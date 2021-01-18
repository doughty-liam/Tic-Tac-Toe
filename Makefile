make ticTacToe: ticTacToe.c
	gcc -ansi -o ticTacToe ticTacToe.c displayGameNew.c checkWin.c computerBlock.c computerWins.c

make clean:
	rm displayGameNew ticTacToe checkWin displayGameNew computerBlock computerPlaysWinning
