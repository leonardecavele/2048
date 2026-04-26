/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:44:53 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 14:34:59 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "gameplay.h"
#include "board.h"

/* game rule, collisions, moves, states ... */
/* go faire pleins de structures pour les differents objets */
/* un peu oriente objet */

t_cell		generate_number(void)
{
	int	rand_value;

	rand_value = rand() % 10;
	if (rand_value == 0)
		return (4);
	else
		return  (2);
}

void	add_one_nbr(t_board *board)
{
	int	available_box[BOARD_MAX * BOARD_MAX];
	int	row;
	int col;
	int index;

	index = 0;
	row = 0;
	while (row < board->size)
	{
		col = 0;
		while (col < board->size)
		{
			if (board->board[row][col] == 0)
				available_box[index++] = row * board->size + col;
			col++;
		}
		row++;
	}
	available_box[index] = -1;
	if (positif_int_tab_len(available_box) == 0)
		return ;
	index = rand() % positif_int_tab_len(available_box);
	col = available_box[index] % board->size;
	row = available_box[index] / board->size;
	board->board[row][col] = generate_number();
}

void	init_board(t_board *board)
{
	int row;
	int col;

	col = rand() % board->size;
	row = rand() % board->size;
	board->board[col][row] = generate_number();
	while(board->board[col][row] != 0)
	{
		col = rand() % board->size;
		row = rand() % board->size;
	}
	board->board[col][row] = generate_number();
}
