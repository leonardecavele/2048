/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:37:28 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 16:52:28 by ldecavel         ###   ########.fr       */
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
