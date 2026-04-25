/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:44:53 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 14:25:57 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "gameplay.h"
#include "libft.h"

/* game rule, collisions, moves, states ... */
/* go faire pleins de structures pour les differents objets */
/* un peu oriente objet */

int		generate_number(void)
{
	int	rand_value;

	rand_value = rand() % 10;
	if (rand_value == 0)
		return (4);
	else
		return  (2);
}

int positif_int_tab_len(int *tab)
{
	int index;

	index = 0;
	while (tab[index] >= 0)
		index++;
	return (index);
}

void print_board(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int row;
	int col;

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			ft_putnbr_fd(board[row][col], 1);
			ft_putchar_fd(' ', 1);
			col++;
		}
		ft_putchar_fd('\n', 1);
		row++;
	}
}

void	add_one_nbr(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int	available_box[BOARD_SIZE * BOARD_SIZE];
	int	row;
	int col;
	int index;

	index = 0;
	row = 0;
	while (++row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			if (board[row][col] == 0)
				available_box[index++] = row * BOARD_SIZE + col;
			col++;
		}
		row++;
	}
	available_box[index] = -1;
	index = rand() % positif_int_tab_len(available_box);
	col = available_box[index] % BOARD_SIZE;
	row = (available_box[index] - col) / BOARD_SIZE;
	board[row][col] = generate_number();
}

void	init_board(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int row;
	int col;

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			board[col][row] = 0;
			col++;
		}
		row++;
	}
	col = rand() % BOARD_SIZE;
	row = rand() % BOARD_SIZE;
	board[col][row] = generate_number();
	while(board[col][row] != 0)
	{
		col = rand() % BOARD_SIZE;
		row = rand() % BOARD_SIZE;
	}
	board[col][row] = generate_number();
}
