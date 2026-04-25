/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:57:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 16:33:12 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern imports */
#include <ncurses.h>

/* intern imports */
#include "render.h"
#include "gameplay.h"
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
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	render_board_values(t_app *app, int start_y, int start_x,
		int cell_h, int cell_w)
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

static int min_int(int a, int b) { if (a < b) return (a); return (b); }

static void	render_board_grid(t_app *app)
{
	int	rows;
	int	cols;
	int	cell_h;
	int	cell_w;
	int	board_h;
	int	board_w;
	int	start_y;
	int	start_x;
	int	y;
	int	x;

	getmaxyx(stdscr, rows, cols);
	cell_h = rows / BOARD_SIZE;
	cell_w = cols / BOARD_SIZE;
	cell_h = min_int(cell_h, cell_w / 2);
	cell_w = cell_h * 2;
	if (cell_h < 2 || cell_w < 4)
	{
		erase();
		mvprintw(0, 0, "Terminal too small");
		refresh();
		return ;
	}
	board_h = cell_h * BOARD_SIZE;
	board_w = cell_w * BOARD_SIZE;
	start_y = (rows - board_h) / 2;
	start_x = (cols - board_w) / 2;
	erase();
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
	y = 0;
	while (y <= BOARD_SIZE)
	{
		x = 0;
		while (x <= BOARD_SIZE)
		{
			mvaddch(start_y + y * cell_h, start_x + x * cell_w, ACS_PLUS);
			x++;
		}
		y++;
	}
	render_board_values(app, start_y, start_x, cell_h, cell_w);
	refresh();
}


extern void game_render(t_app *app)
{
	render_board_grid(app);
	/* affichage du jeu */
}
