/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:57:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 18:08:01 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>

/* intern */
#include "render.h"
#include "gameplay.h"
#include "helpers.h"
#include "app.h"
#include "font.h"

extern t_errcode game_update(t_app *app)
{
	app->user_input = getch();

	if (app->user_input == ERR)
		return NO_ERROR;

	if (app->user_input == 27)
		app->current_view = &app->end_view;

	if (app->user_input == KEY_UP) {
		if (move_up(app))
			add_one_nbr(&app->board);
	}
	else if (app->user_input == KEY_DOWN) {
		if (move_down(app))
			add_one_nbr(&app->board);
	}
	else if (app->user_input == KEY_LEFT) {
		if (move_left(app))
			add_one_nbr(&app->board);
	}
	else if (app->user_input == KEY_RIGHT) {
		if (move_right(app))
			add_one_nbr(&app->board);
	}

	if (are_you_winning_son(&app->board) && !(app->state & WIN)) {
		app->state |= WIN;
		app->current_view = &app->end_view;
	}

	else if (is_loosed(&app->board)) {
		app->state |= DEFEAT;
		app->current_view = &app->end_view;
	}

	return NO_ERROR;
}

static int draw_values_color(
	t_cell value, int y, int x, int cell_h, int cell_w
)
{
	int pair;
	
	switch (value)
	{
		case 2:    pair = 1; break;
		case 4:    pair = 2; break;
		case 8:    pair = 3; break;
		case 16:   pair = 4; break;
		case 32:   pair = 5; break;
		case 64:   pair = 6; break;
		case 128:  pair = 7; break;
		case 256:  pair = 8; break;
		case 512:  pair = 9; break;
		case 1024: pair = 10; break;
		case 2048: pair = 11; break;
		case 4096: pair = 12; break;
		default:   pair = 13; break;
	}
	
	attron(COLOR_PAIR(pair));
	
	// Fill the cell with colored background
	int i, j;
	for (i = 1; i < cell_h; i++)
	{
		for (j = 2; j < cell_w - 1; j++)
		{
			mvaddch(y + i, x + j, ' ');
		}
	}
	
	return pair;
}

static void	draw_board_values(
	t_app *app, int start_y, int start_x, int cell_h, int cell_w
)
{
	short	fg;
	short	bg;
	int	cell_y;
	int	cell_x;
	int pair;
	t_cell val;

	for (int y = 0; y < app->board.size; y++) {
		for (int x = 0; x < app->board.size; x++) {
			val = app->board.board[y][x];
			cell_y = start_y + y * cell_h;
			cell_x = start_x + x * cell_w;

			if (val != 0)
			{
				attron(A_BOLD);
				pair = draw_values_color(val, cell_y, cell_x, cell_h, cell_w);
				int len = nbrlen(val);
				int v_y = cell_y + cell_h / 2 + 1;
				int v_x = cell_x + (cell_w - len) / 2;
				int current_idx = y * app->board.size + x;

				if (current_idx == app->board.last_modif)
				{
					attroff(COLOR_PAIR(pair));
					pair_content(pair, &fg, &bg);
					init_pair(20, COLOR_WHITE, bg);
					pair = 20;
					attron(A_BLINK | COLOR_PAIR(20));
				}
				if (draw_ascii_value(val, v_y, v_x, cell_h, cell_w))
					mvprintw(v_y, v_x, "%u", (unsigned int)val);

				if (current_idx == app->board.last_modif)
					attroff(A_BLINK);
				attroff(COLOR_PAIR(pair) | A_BOLD);
			}
		}
	}
}


static chtype	get_grid_joint(int y, int x, int size)
{
	if (y == 0 && x == 0)
		return ACS_ULCORNER;
	if (y == 0 && x == size)
		return ACS_URCORNER;
	if (y == size && x == 0)
		return ACS_LLCORNER;
	if (y == size && x == size)
		return ACS_LRCORNER;
	if (y == 0)
		return ACS_TTEE;
	if (y == size)
		return ACS_BTEE;
	if (x == 0)
		return ACS_LTEE;
	if (x == size)
		return ACS_RTEE;
	return ACS_PLUS;
}

static void	draw_grid_lines(int start_y, int start_x, int cell_h, int cell_w, int size)
{
	int	board_h;
	int	board_w;

	board_h = cell_h * size;
	board_w = cell_w * size;
	for (int y = 0; y <= size; y++)
		mvhline(start_y + y * cell_h, start_x, ACS_HLINE, board_w);
	for (int x = 0; x <= size; x++)
		mvvline(start_y, start_x + x * cell_w, ACS_VLINE, board_h);
}

static void	draw_grid_joints(int start_y, int start_x, int cell_h, int cell_w, int size)
{
	for (int y = 0; y <= size; y++) {
		for (int x = 0; x <= size; x++) {
			mvaddch(
				start_y + y * cell_h,
				start_x + x * cell_w,
				get_grid_joint(y, x, size)
			);
		}
	}
}

static void	render_board(t_app *app)
{
	int r = app->screen.rows;
	int c = app->screen.cols;

	int cell_h = r / app->board.size;
	int cell_w = c / app->board.size;
	cell_h = min(cell_h, cell_w / 2);
	cell_w = cell_h * 2;

	int board_h = cell_h * app->board.size;
	int board_w = cell_w * app->board.size;

	int start_x = (c - board_w) / 2;
	int start_y = (r - board_h) / 2;

	draw_grid_lines(start_y, start_x, cell_h, cell_w, app->board.size);
	draw_grid_joints(start_y, start_x, cell_h, cell_w, app->board.size);
	draw_board_values(app, start_y, start_x, cell_h, cell_w);
}


extern t_errcode game_render(t_app *app)
{
	if (!check_size(app))
		return NO_ERROR;

	erase();
	render_board(app);
	refresh();
	return NO_ERROR;
}
