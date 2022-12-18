#include "tictactoe.h"

int	main(void) {
	int	**board;
	int	i;

	board = malloc(3 * sizeof(int *));
	i = -1;
	while (++i < 3)
		board[i] = malloc(3 * sizeof(int));
	printf("For playing insert input like this: \"11\", this is for playing in the middle of the board.\nPlayer O start:\n");
	init_board(board);
	while (1) {
		print_board(board);
		make_move(board);
		if (check_winner(board)) {
			free(board);
			return (1);
		}
	}
	free_board(board);
	return (0);
}
