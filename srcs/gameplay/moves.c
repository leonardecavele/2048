/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:54:20 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 20:32:45 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"
#include "app.h"
#include "libft.h"
#include "board.h"

t_cell	can_move(int coord1, int coord2, int combined[BOARD_MAX], t_board *board)
{
	int	index;
	int	nbr1;
	int	nbr2;

	nbr1 = board->board[coord1 / board->size][coord1 % board->size];
	nbr2 = board->board[coord2 / board->size][coord2 % board->size];
	if (nbr2 == 0)
		return (1);
	if (nbr1 != nbr2)
		return (0);
	index = 0;
	while(index < board->size && combined[index] != -1)
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
	int combined[BOARD_MAX];
	int has_moved;

	row = 0;
	has_moved = 0;
	while (row < app->board.size)
	{
		col = 1;
		init_combined(combined);
		while(col < app->board.size)
		{
			if (app->board.board[row][col] == 0)
			{
				col++;
				continue;
			}
			move = col;
			while (move > 0)
			{
				is_moving = can_move(
						row * app->board.size + move,
						row * app->board.size + move - 1,
						combined,
						&app->board
					);
				if (is_moving && !has_moved)
					has_moved = 1;
				if (is_moving == 1)
					app->board.board[row][move - 1] = app->board.board[row][move];
				else if (is_moving == 2)
				{
					app->current_score.score += app->board.board[row][move] * 2;
					app->board.board[row][move - 1] = app->board.board[row][move] * 2;
				}
				else
					break;
				app->board.board[row][move] = 0;
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
	int combined[BOARD_MAX];
	int has_moved;

	has_moved = 0;
	row = 0;
	while (row < app->board.size)
	{
		col = app->board.size - 2; // Start from the right side
		init_combined(combined);
		while (col >= 0)
		{
			if (app->board.board[row][col] != 0)
			{
				move = col;
				while (move < app->board.size - 1)
				{
					is_moving = can_move(row * app->board.size + move, row * app->board.size + move + 1, combined, &app->board);
					if (is_moving && !has_moved)
						has_moved = 1;
					if (is_moving == 1)
						app->board.board[row][move + 1] = app->board.board[row][move];
					else if (is_moving == 2)
					{
						app->current_score.score += app->board.board[row][move] * 2;
						app->board.board[row][move + 1] = app->board.board[row][move] * 2;
					}
					else
						break;
					app->board.board[row][move] = 0;
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
	int combined[BOARD_MAX];
	int has_moved;

	has_moved = 0;
	col = 0;
	while (col < app->board.size)
	{
		row = 1; // Start from second row
		init_combined(combined);
		while (row < app->board.size)
		{
			if (app->board.board[row][col] != 0)
			{
				move = row;
				while (move > 0)
				{
					is_moving = can_move(move * app->board.size + col, (move - 1) * app->board.size + col, combined, &app->board);
					if (is_moving && !has_moved)
						has_moved = 1;
					if (is_moving == 1)
						app->board.board[move - 1][col] = app->board.board[move][col];
					else if (is_moving == 2)
					{
						app->current_score.score += app->board.board[move][col] * 2;
						app->board.board[move - 1][col] = app->board.board[move][col] * 2;
					}
					else
						break;
					app->board.board[move][col] = 0;
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
	int combined[BOARD_MAX];
	int has_moved;

	has_moved = 0;
	col = 0;
	while (col < app->board.size)
	{
		row = app->board.size - 2; // Start from bottom-ish
		init_combined(combined);
		while (row >= 0)
		{
			if (app->board.board[row][col] != 0)
			{
				move = row;
				while (move < app->board.size - 1)
				{
					is_moving = can_move(move * app->board.size + col, (move + 1) * app->board.size + col, combined, &app->board);
					if (is_moving && !has_moved)
						has_moved = 1;
					if (is_moving == 1)
						app->board.board[move + 1][col] = app->board.board[move][col];
					else if (is_moving == 2)
					{
						app->current_score.score += app->board.board[move][col] * 2;
						app->board.board[move + 1][col] = app->board.board[move][col] * 2;
					}
					else
						break;
					app->board.board[move][col] = 0;
					move++;
				}
			}
			row--;
		}
		col++;
	}
	return (has_moved);
}
