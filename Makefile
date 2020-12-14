make ticTacToe: ticTacToe.c
	gcc -ansi -o ticTacToe ticTacToe.c displayGame.o checkWin.o

make displayGame: displayGame.c
	gcc -ansi -c displayGame.c

make checkWin: checkWin.c
	gcc -ansi -c checkWin.c

make clean:
	rm displayGame.o ticTacToe checkWin.o
