#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char option[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int player1 =1 , player2 = 2, i , game = 0, win = 0, score1 = 0, score2 = 0;
char x = 'x', o = 'o', choose = ' ', yes;

void reset();
void board();
void play(int player, char mark);
void checkwin();

void main() {

	board();
	do {
		
			play(player1, x);
			getchar();
			if (win == 0) {
				play(player2, o);
				getchar();
			}
			else if(win == 1 || win == 2)
			{
				win = 0;
			}
		} while (game != 1);
		
	return EXIT_SUCCESS;
}

void board() {

	system("cls");
	printf("\n\n\tTic Tac Toe\n\n");

	printf("Player 1 (X)  -  Player 2 (O)\n\n");
	printf("Player 1 Score %d || Player 2 Score %d\n\n\n", score1, score2);


	printf("             |     |     \n");
	printf("         %c   |   %c |  %c \n", option[0], option[1], option[2]);

	printf("        _____|_____|_____\n");
	printf("             |     |     \n");

	printf("          %c  |   %c |  %c \n", option[3], option[4], option[5]);

	printf("        _____|_____|_____\n");
	printf("             |     |     \n");

	printf("          %c  |   %c |  %c \n", option[6], option[7], option[8]);
	printf("             |     |     \n\n");

}

void play(int player, char mark) {
	if(game == 1){
		return EXIT_SUCCESS;
	}
	else if (player == 1) {
		printf("Player%d: insert the number where you want insert your x\n", player);
	}
	else {
		printf("Player%d: insert the number where you want insert your 0\n", player);
	}
	scanf_s("%c", &choose);
	for (i = 0; i <= 9; i++) {
		if (option[i] == choose) {
			option[i] = mark;
			board();
			checkwin();
		}
	}
}

void checkwin() {
	if ((option[0] == 'x' && option[1] == 'x' && option[2] == 'x') || (option[3] == 'x' && option[4] == 'x' && option[5] == 'x') || (option[6] == 'x' && option[7] == 'x' && option[8] == 'x') || (option[0] == 'x' && option[4] == 'x' && option[8] == 'x') || (option[6] == 'x' && option[4] == 'x' && option[2] == 'x') || (option[1] == 'x' && option[4] == 'x' && option[7] == 'x') || (option[2] == 'x' && option[5] == 'x' && option[8] == 'x') || (option[3] == 'x' && option[6] == 'x' && option[9] == 'x')) {
		printf("The winner is player 1\n\n");
		game = 1;
		win = 1;
		score1++;
		reset();
	}
	else if
		((option[0] == 'o' && option[1] == 'o' && option[2] == 'o') || (option[3] == 'o' && option[4] == 'o' && option[5] == 'o') || (option[6] == 'o' && option[7] == 'o' && option[8] == 'o') || (option[0] == 'o' && option[4] == 'o' && option[8] == 'o') || (option[6] == 'o' && option[4] == 'o' && option[2] == 'o') || (option[1] == 'o' && option[4] == 'o' && option[7] == 'o') || (option[2] == 'o' && option[5] == 'o' && option[8] == 'o') || (option[3] == 'o' && option[6] == 'o' && option[9] == 'o')) {
		printf("The winner is player 2\n\n");
		game = 1;
		win = 2;
		score2++;
		reset();
	}
	else if (option[0] != '1' && option[1] != '2' && option[2] != '3' && option[3] != '4' && option[4] != '5' && option[5] != '6' && option[7] != '8' && option[8] != '9') {
		printf("Draw!\n");
		reset();
	}
}

void reset() {

	system("pause");
	printf("you wanna play again s/n?\n");
	getchar();
	scanf_s("%c", &yes);
	if (yes == 's') {
		option[0] = '1';
		option[1] = '2';
		option[2] = '3';
		option[3] = '4';
		option[4] = '5';
		option[5] = '6';
		option[6] = '7';
		option[7] = '8';
		option[8] = '9';
		game = 0;
		board();
		
	}


}


