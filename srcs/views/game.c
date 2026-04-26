/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:57:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 12:38:21 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>

/* intern */
#include "render.h"
#include "gameplay.h"
#include "helpers.h"
#include "app.h"

extern t_errcode game_update(t_app *app)
{
	app->user_input = getch();

	if (app->user_input == ERR)
		return NO_ERROR;

	if (are_you_winning_son(app->board) && !app->win) {
		app->win = true;
		app->current_view = &app->end_view;
	}
	else if (is_loosed(app->board)) {
		app->defeat = true;
		app->current_view = &app->end_view;
	}

	if (app->user_input == 27)
		app->current_view = &app->end_view;

	if (app->user_input == KEY_UP) {
		move_up(app->board);
		add_one_nbr(app->board);
	}
	else if (app->user_input == KEY_DOWN) {
		move_down(app->board);
		add_one_nbr(app->board);
	}
	else if (app->user_input == KEY_LEFT) {
		move_left(app->board);
		add_one_nbr(app->board);
	}
	else if (app->user_input == KEY_RIGHT) {
		move_right(app->board);
		add_one_nbr(app->board);
	}

	return NO_ERROR;
}


static void	draw_board_values(
	t_app *app, int start_y, int start_x, int cell_h, int cell_w
)
{
	int	y;
	int	x;
	int	value_y;
	int	value_x;
	int	len;

	y = 0;
	while (y < BOARD_SIZE)
	{
		x = 0;
		while (x < BOARD_SIZE)
		{
			if (app->board[y][x] != 0)
			{
				len = nbrlen(app->board[y][x]);
				value_y = start_y + y * cell_h + cell_h / 2;
				value_x = start_x + x * cell_w + (cell_w - len) / 2;
				mvprintw(value_y, value_x, "%u",
					(unsigned int)app->board[y][x]);
			}
			x++;
		}
		y++;
	}
}


static chtype	get_grid_joint(int y, int x)
{
	if (y == 0 && x == 0)
		return (ACS_ULCORNER);
	if (y == 0 && x == BOARD_SIZE)
		return (ACS_URCORNER);
	if (y == BOARD_SIZE && x == 0)
		return (ACS_LLCORNER);
	if (y == BOARD_SIZE && x == BOARD_SIZE)
		return (ACS_LRCORNER);
	if (y == 0)
		return (ACS_TTEE);
	if (y == BOARD_SIZE)
		return (ACS_BTEE);
	if (x == 0)
		return (ACS_LTEE);
	if (x == BOARD_SIZE)
		return (ACS_RTEE);
	return (ACS_PLUS);
}

static void	draw_grid_lines(int start_y, int start_x, int cell_h, int cell_w)
{
	int	y;
	int	x;
	int	board_h;
	int	board_w;

	board_h = cell_h * BOARD_SIZE;
	board_w = cell_w * BOARD_SIZE;
	y = 0;
	while (y <= BOARD_SIZE)
	{
		mvhline(start_y + y * cell_h, start_x, ACS_HLINE, board_w);
		y++;
	}
	x = 0;
	while (x <= BOARD_SIZE)
	{
		mvvline(start_y, start_x + x * cell_w, ACS_VLINE, board_h);
		x++;
	}
}

static void	draw_grid_joints(int start_y, int start_x, int cell_h, int cell_w)
{
	int	y;
	int	x;

	y = 0;
	while (y <= BOARD_SIZE)
	{
		x = 0;
		while (x <= BOARD_SIZE)
		{
			mvaddch(
				start_y + y * cell_h,
				start_x + x * cell_w,
				get_grid_joint(y, x)
			);
			x++;
		}
		y++;
	}
}

static void	render_board(t_app *app)
{
	int r = app->screen.rows;
	int c = app->screen.cols;

	int cell_h = r / BOARD_SIZE;
	int cell_w = c / BOARD_SIZE;
	cell_h = min(cell_h, cell_w / 2);
	cell_w = cell_h * 2;

	int board_h = cell_h * BOARD_SIZE;
	int board_w = cell_w * BOARD_SIZE;

	int start_x = (c - board_w) / 2;
	int start_y = (r - board_h) / 2;

	draw_grid_lines(start_y, start_x, cell_h, cell_w);
	draw_grid_joints(start_y, start_x, cell_h, cell_w);
	draw_board_values(app, start_y, start_x, cell_h, cell_w);
}


extern t_errcode game_render(t_app *app)
{
	check_size(app);

	// DELETE
	app->win = true;
	erase();
	render_board(app);
	refresh();
	return NO_ERROR;
}
