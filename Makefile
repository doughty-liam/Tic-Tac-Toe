make ticTacToe: ticTacToe.c
	gcc -ansi -o ticTacToe ticTacToe.c displayGameNew.c checkWin.c

make clean:
	rm displayGameNew ticTacToe checkWin
