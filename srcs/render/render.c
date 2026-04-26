/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:37:28 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 12:00:06 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
/* intern */
#include "error.h"
#include "render.h"
#include "libft.h"
#include "app.h"
#include "helpers.h"

extern void handle_resize(void)
{
	endwin();
	refresh();
	clear();
}

extern t_errcode ncurses_init(void)
{
	if (initscr() == NULL
		|| cbreak() == ERR
		|| noecho() == ERR
		|| keypad(stdscr, TRUE) == ERR
		|| nodelay(stdscr, FALSE) == ERR)
		return NCURSES_ERROR;

	curs_set(0);
	set_escdelay(25);
	timeout(16);

	if (has_colors() == TRUE) {
		start_color();
		use_default_colors();
	}

	refresh();
	return (NO_ERROR);
}

extern void print_centered(t_app *app, int y, const char *str)
{
	int c = app->screen.cols;
	int x = max(0, (c - (int)ft_strlen(str)) / 2);

	mvprintw(y, x, "%s", str);
}

extern void render_too_small(t_app *app)
{
	int r = app->screen.rows;
	int c = app->screen.cols;

	(void)c;
	print_centered(app, r / 2, "Windows too small, please increase size");
}

extern void render_invalid_ratio(t_app *app)
{
	int r = app->screen.rows;
	int c = app->screen.cols;

	(void)c;
	print_centered(app, r / 2, "Windows has an invalid ratio");
}

extern void render_frame(t_app *app, int y, int box_w, int box_h)
{
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

extern bool	screen_ratio_is_bad(t_app *app)
{
	int	r;
	int	c;

	r = app->screen.rows;
	c = app->screen.cols;
	if ((long)c * MAX_WIDTH_RATIO_DEN
		> (long)r * MAX_WIDTH_RATIO_NUM * TERM_CHAR_RATIO)
		return (true);
	if ((long)c * MIN_WIDTH_RATIO_DEN
		< (long)r * MIN_WIDTH_RATIO_NUM)
		return (true);
	return (false);
}

extern void check_size(t_app *app)
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
}
