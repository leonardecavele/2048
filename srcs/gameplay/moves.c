/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:54:20 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 13:55:45 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"
#include "app.h"
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

int	move_left(t_app *app)
{
	int row;
	int col;
	int move;
	int is_moving;
	int combined[BOARD_SIZE];
	int has_moved;

	row = 0;
	has_moved = 0;
	while (row < BOARD_SIZE)
	{
		col = 1;
		ft_bzero(combined, sizeof(int) * BOARD_SIZE);
		while(col < BOARD_SIZE)
		{
			if (app->board[row][col] == 0)
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
						app->board
					);
				if (is_moving && !has_moved)
					has_moved = 1;
				if (is_moving == 1)
					app->board[row][move - 1] = app->board[row][move];
				else if (is_moving == 2)
				{
					app->score += app->board[row][move] * 2;
					app->board[row][move - 1] = app->board[row][move] * 2;
				}
				else
				{
					move--;
					break;
				}
				app->board[row][move] = 0;
				move--;
			}
			col++;
		}
		row++;
	}
	return (has_moved);
}

int	move_right(t_app *app)
{
	int row, col, move, is_moving;
	int combined[BOARD_SIZE];
	int has_moved;

	has_moved = 0;
	row = 0;
	while (row < BOARD_SIZE)
	{
		col = BOARD_SIZE - 2; // Start from the right side
		ft_bzero(combined, sizeof(int) * BOARD_SIZE);
		while (col >= 0)
		{
			if (app->board[row][col] != 0)
			{
				move = col;
				while (move < BOARD_SIZE - 1)
				{
					is_moving = can_move(row * BOARD_SIZE + move, row * BOARD_SIZE + move + 1, combined, app->board);
					if (is_moving && !has_moved)
						has_moved = 1;
					if (is_moving == 1)
						app->board[row][move + 1] = app->board[row][move];
					else if (is_moving == 2)
					{
						app->score += app->board[row][move] * 2;
						app->board[row][move + 1] = app->board[row][move] * 2;
					}
					else
						break;
					app->board[row][move] = 0;
					if (is_moving == 2) break; // Stop after a merge
					move++;
				}
			}
			col--;
		}
		row++;
	}
	return (has_moved);
}

int	move_up(t_app *app)
{
	int row, col, move, is_moving;
	int combined[BOARD_SIZE];
	int has_moved;

	has_moved = 0;
	col = 0;
	while (col < BOARD_SIZE)
	{
		row = 1; // Start from second row
		ft_bzero(combined, sizeof(int) * BOARD_SIZE);
		while (row < BOARD_SIZE)
		{
			if (app->board[row][col] != 0)
			{
				move = row;
				while (move > 0)
				{
					is_moving = can_move(move * BOARD_SIZE + col, (move - 1) * BOARD_SIZE + col, combined, app->board);
					if (is_moving && !has_moved)
						has_moved = 1;
					if (is_moving == 1)
						app->board[move - 1][col] = app->board[move][col];
					else if (is_moving == 2)
					{
						app->score += app->board[move][col] * 2;
						app->board[move - 1][col] = app->board[move][col] * 2;
					}
					else
						break;
					app->board[move][col] = 0;
					if (is_moving == 2) break;
					move--;
				}
			}
			row++;
		}
		col++;
	}
	return (has_moved);
}

int	move_down(t_app *app)
{
	int row, col, move, is_moving;
	int combined[BOARD_SIZE];
	int has_moved;

	has_moved = 0;
	col = 0;
	while (col < BOARD_SIZE)
	{
		row = BOARD_SIZE - 2; // Start from bottom-ish
		ft_bzero(combined, sizeof(int) * BOARD_SIZE);
		while (row >= 0)
		{
			if (app->board[row][col] != 0)
			{
				move = row;
				while (move < BOARD_SIZE - 1)
				{
					is_moving = can_move(move * BOARD_SIZE + col, (move + 1) * BOARD_SIZE + col, combined, app->board);
					if (is_moving && !has_moved)
						has_moved = 1;
					if (is_moving == 1)
						app->board[move + 1][col] = app->board[move][col];
					else if (is_moving == 2)
					{
						app->score += app->board[move][col] * 2;
						app->board[move + 1][col] = app->board[move][col] * 2;
					}
					else
						break;
					app->board[move][col] = 0;
					if (is_moving == 2) break;
					move++;
				}
			}
			row--;
		}
		col++;
	}
	return (has_moved);
}
