#include "tictactoe.h"

int	player = 0;

void	make_move(int **board) {
	char	*move;
	int		first_h;
	int		second_h;
	int		input_ok;

	input_ok = 0;
	move = malloc(2 * sizeof(char));
	while (1) {
		printf("Insert your move: ");
		scanf("%s", move);
		if (strlen(move) != 2)
			printf("This lenght is invalid! Try again.\n");
		else if ((move[0] < '0' || move[0] > '2') || \
			(move[1] < '0' || move[1] > '2'))
			printf("The input is not a number between '0' and '2'! Try again.\n");
		else
			input_ok = 1;
		if (input_ok) {
			first_h = atoi(&move[0]) / 10;
			second_h = atoi(&move[1]);
			if (board[first_h][second_h] == ' ') {
				if (player % 2 == 1)
					board[first_h][second_h] = 'X';
				else
					board[first_h][second_h] = 'O';
				player++;
				break;
			}
			else
				printf("It's already occupied! Try again.\n");
		}
	}
}

int	check_winner(int **board) {
	int	i;

	i = -1;
	while (++i < 3) {
		if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
			print_board(board);
			printf("The player O win!\n");
			return (1);
		}
		if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
			print_board(board);
			printf("The player X win!\n");
			return (1);
		}
	}
	i = -1;
	while (++i < 3) {
		if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') {
			print_board(board);
			printf("The player O win!\n");
			return (1);
		}
		if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') {
			print_board(board);
			printf("The player X win!\n");
			return (1);
		}
	}
	i = -1;
	while (++i < 3) {
		if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
			print_board(board);
			printf("The player O win!\n");
			return (1);
		}
		if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
			print_board(board);
			printf("The player X win!\n");
			return (1);
		}
	}
	return (0);
}

void	init_board(int **board) {
	int	i;
	int	j;

	i = -1;
	while (++i < 3) {
		j = -1;
		while (++j < 3) {
			board[i][j] = ' ';
		}
	}
}

void	print_board(int **board) {
	int	i;

	i = -1;
	printf("\n  0   1   2\n");
	while (++i < 3) {
		printf("%d %c | %c | %c\n", i,board[i][0], board[i][1], board[i][2]);
		if (i < 2)
			printf("  ---------\n");
	}
	printf("\n");
}

void	free_board(int **board) {
	int	i;

	i = -1;
	while (++i < 3)
		free(board[i]);
	free(board);
}
