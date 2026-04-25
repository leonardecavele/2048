/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:46:05 by gabach            #+#    #+#             */
/*   Updated: 2026/04/25 17:16:57 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

int	is_win_value_valid(void)
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

	if (power_of_2 > (BOARD_SIZE * BOARD_SIZE))
		return (0);

	return (1);
}

int	are_you_winning_son(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int	row;
	int col;
	int win_value;

	if (is_win_value_valid())
		win_value = WIN_VALUE;
	else
		win_value = 2048;

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			if (board[row][col] == win_value)
				return (1);
			col++;
		}
		row++;
	}
	return 0;
}

int	is_loosed(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int row;
	int col;
	int	nbr;

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			nbr = board[row][col];
			if (nbr == 0)
				return (0);
			if (row > 0 && board[row - 1][col] == nbr)
				return (0);
			if (row < BOARD_SIZE - 2 && board[row + 1][col] == nbr)
				return (0);
			if (col > 0 && board[row][col - 1] == nbr)
				return (0);
			if (col < BOARD_SIZE - 2 && board[row][col + 1] == nbr)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
