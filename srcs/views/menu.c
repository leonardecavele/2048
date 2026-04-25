/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 21:17:58 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern imports */
#include <ncurses.h>
/* intern imports */
#include "gameplay.h"
#include "app.h"

extern void menu_update(t_app *app)
{
	app->user_input = getch();

	if (app->user_input == ERR)
		return ;

	if (app->user_input == '\n'
		|| app->user_input == '\r'
		|| app->user_input == 'p' || app->user_input == 'P')
		app->current_view = &app->game_view;

	if (app->user_input == 27)
		app->exit = true;
}

static void	render_title_frame(t_app *app, int y)
{
	int	box_w = 31;
	int	box_h = 14;
	int start_y = y - 1;
	int start_x = (app->screen.cols - box_w) / 2;

	attron(A_BOLD);
	mvaddch(start_y, start_x, ACS_ULCORNER);
	mvhline(start_y, start_x + 1, ACS_HLINE, box_w - 2);
	mvaddch(start_y, start_x + box_w - 1, ACS_URCORNER);

	for (int i = 1; i < box_h - 1; i++) {
		mvaddch(start_y + i, start_x, ACS_VLINE);
		mvaddch(start_y + i, start_x + box_w - 1, ACS_VLINE);
	}

	mvaddch(start_y + box_h - 1, start_x, ACS_LLCORNER);
	mvhline(start_y + box_h - 1, start_x + 1, ACS_HLINE, box_w - 2);
	mvaddch(start_y + box_h - 1, start_x + box_w - 1, ACS_LRCORNER);
	attroff(A_BOLD);
}

static void render_title(t_app *app, int y)
{
	print_centered(app, y + 0,  "  ___   ___  _  _  ___  ");
	print_centered(app, y + 1,  " |__ \\ / _ \\| || ||__ \\ ");
	print_centered(app, y + 2,  "    ) | | | | || |_  ) |");
	print_centered(app, y + 3,  "   / /| | | |__   _|/ / ");
	print_centered(app, y + 4,  "  / /_| |_| |  | | / /_ ");
	print_centered(app, y + 5,  " |____|\\___/   |_||____|");
}

static void	render_play_button(t_app *app, int y)
{
	print_centered(app, y + 7, "                       ");
	attron(A_REVERSE | A_BOLD);
	print_centered(app, y + 8, "   PLAY (P)   ");
	print_centered(app, y + 10, "  SCORES (S)  ");
	attroff(A_REVERSE | A_BOLD);
	print_centered(app, y + 11, "                       ");
}


extern void menu_render(t_app *app)
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

	erase();
	render_title_frame(app, (r / 2) - 5);
	render_title(app, (r / 2) - 5);
	render_play_button(app, (r / 2) - 5);
	refresh();
}
