/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:57:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 17:31:41 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern imports */
#include <ncurses.h>

/* intern imports */
#include "render.h"
#include "gameplay.h"
#include "helpers.h"
#include "app.h"

extern void game_update(t_app *app)
{
	app->user_input = getch();

	if (app->user_input == ERR)
		return ;

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
}

static int	nbr_len(t_cell nbr)
{
	int	len = 0;

	if (nbr == 0)
		return (1);

	while (nbr > 0) {
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	render_board_values(
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
				len = nbr_len(app->board[y][x]);
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

static void	render_board_grid(t_app *app)
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

	erase();
	draw_grid_lines(start_y, start_x, cell_h, cell_w);
	draw_grid_joints(start_y, start_x, cell_h, cell_w);
	render_board_values(app, start_y, start_x, cell_h, cell_w);
	refresh();
}


extern void game_render(t_app *app)
{
	getmaxyx(stdscr, app->screen.rows, app->screen.cols);

	int r = app->screen.rows;
	int c = app->screen.cols;

	if (r < MIN_ROW || c < MIN_COL) {
		render_too_small(app);
		return;
	}

	if (screen_ratio_is_bad(app)) {
		render_invalid_ratio(app);
		return;
	}

	render_board_grid(app);
}
