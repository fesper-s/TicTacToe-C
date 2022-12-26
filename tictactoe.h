#ifndef TICTACTOE_H
# define TICTACTOE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	make_move(int **board);
int		check_winner(int **board);
void	init_board(int **board);
void	print_board(int **board);
void	free_board(int **board);

#endif
