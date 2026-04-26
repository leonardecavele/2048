/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:46:05 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 14:32:16 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"
#include "board.h"

int	is_win_value_valid(int size)
{
	int	win_value;
	int	power_of_2;

	win_value = WIN_VALUE;
	power_of_2 = 0;

	if (win_value < 2 || (win_value & (win_value - 1)) != 0)
		return (0);

	int temp = win_value;
	while (temp > 1)
	{
		temp >>= 1;
		power_of_2++;
	}

	if (power_of_2 > (size * size) + 1)
		return (0);

	return (1);
}

int	are_you_winning_son(t_board *board)
{
	int	row;
	int col;
	t_cell win_value;

	if (is_win_value_valid(board->size))
		win_value = WIN_VALUE;
	else
		win_value = 2048;

	row = 0;
	while (row < board->size)
	{
		col = 0;
		while (col < board->size)
		{
			if (board->board[row][col] == win_value)
				return (1);
			col++;
		}
		row++;
	}
	return 0;
}

int	is_loosed(t_board *board)
{
	int 	row;
	int 	col;
	t_cell	nbr;

	row = 0;
	while (row < board->size)
	{
		col = 0;
		while (col < board->size)
		{
			nbr = board->board[row][col];
			if (nbr == 0)
				return (0);
			if (row > 0 && board->board[row - 1][col] == nbr)
				return (0);
			if (row < board->size - 2 && board->board[row + 1][col] == nbr)
				return (0);
			if (col > 0 && board->board[row][col - 1] == nbr)
				return (0);
			if (col < board->size - 2 && board->board[row][col + 1] == nbr)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
