/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:54:20 by gabach            #+#    #+#             */
/*   Updated: 2026/04/25 16:29:41 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"
#include "libft.h"

t_cell	can_move(int coord1, int coord2, int combined[BOARD_SIZE], t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int	index;
	int	nbr1;
	int	nbr2;

	nbr1 = board[coord1 / BOARD_SIZE][coord1 % BOARD_SIZE];
	nbr2 = board[coord2 / BOARD_SIZE][coord2 % BOARD_SIZE];
	if (nbr2 == 0)
		return (1);
	if (nbr1 != nbr2)
		return (0);
	index = 0;
	while(index < BOARD_SIZE && combined[index] !=0)
	{
		if (coord1 == combined[index] || coord2 == combined[index])
			return (0);
		index++;
	}
	combined[index] = coord2;
	return (2);
}

void	move_left(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int row;
	int col;
	int move;
	int is_moving;
	int combined[BOARD_SIZE];

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 1;
		ft_bzero(combined, sizeof(int) * BOARD_SIZE);
		while(col < BOARD_SIZE)
		{
			if (board[row][col] == 0)
			{
				col++;
				continue;
			}
			move = col;
			while (move > 0)
			{
				is_moving = can_move(
						row * BOARD_SIZE + move,
						row * BOARD_SIZE + move - 1,
						combined,
						board
					);
				if (is_moving == 1)
					board[row][move - 1] = board[row][move];
				else if (is_moving == 2)
					board[row][move - 1] = board[row][move] * 2;
				else
				{
					move--;
					break;
				}
				board[row][move] = 0;
				move--;
			}
			col++;
		}
		row++;
	}
}

void	move_right(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int row, col, move, is_moving;
	int combined[BOARD_SIZE];

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = BOARD_SIZE - 2; // Start from the right side
		ft_bzero(combined, sizeof(int) * BOARD_SIZE);
		while (col >= 0)
		{
			if (board[row][col] != 0)
			{
				move = col;
				while (move < BOARD_SIZE - 1)
				{
					is_moving = can_move(row * BOARD_SIZE + move, row * BOARD_SIZE + move + 1, combined, board);
					if (is_moving == 1)
						board[row][move + 1] = board[row][move];
					else if (is_moving == 2)
						board[row][move + 1] = board[row][move] * 2;
					else
						break;
					board[row][move] = 0;
					if (is_moving == 2) break; // Stop after a merge
					move++;
				}
			}
			col--;
		}
		row++;
	}
}

void	move_up(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int row, col, move, is_moving;
	int combined[BOARD_SIZE];

	col = 0;
	while (col < BOARD_SIZE)
	{
		row = 1; // Start from second row
		ft_bzero(combined, sizeof(int) * BOARD_SIZE);
		while (row < BOARD_SIZE)
		{
			if (board[row][col] != 0)
			{
				move = row;
				while (move > 0)
				{
					is_moving = can_move(move * BOARD_SIZE + col, (move - 1) * BOARD_SIZE + col, combined, board);
					if (is_moving == 1)
						board[move - 1][col] = board[move][col];
					else if (is_moving == 2)
						board[move - 1][col] = board[move][col] * 2;
					else
						break;
					board[move][col] = 0;
					if (is_moving == 2) break;
					move--;
				}
			}
			row++;
		}
		col++;
	}
}

void	move_down(t_cell board[BOARD_SIZE][BOARD_SIZE])
{
	int row, col, move, is_moving;
	int combined[BOARD_SIZE];

	col = 0;
	while (col < BOARD_SIZE)
	{
		row = BOARD_SIZE - 2; // Start from bottom-ish
		ft_bzero(combined, sizeof(int) * BOARD_SIZE);
		while (row >= 0)
		{
			if (board[row][col] != 0)
			{
				move = row;
				while (move < BOARD_SIZE - 1)
				{
					is_moving = can_move(move * BOARD_SIZE + col, (move + 1) * BOARD_SIZE + col, combined, board);
					if (is_moving == 1)
						board[move + 1][col] = board[move][col];
					else if (is_moving == 2)
						board[move + 1][col] = board[move][col] * 2;
					else
						break;
					board[move][col] = 0;
					if (is_moving == 2) break;
					move++;
				}
			}
			row--;
		}
		col++;
	}
}
