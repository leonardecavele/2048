/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 19:01:37 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
#include <stdio.h>
/* intern */
#include "gameplay.h"
#include "board.h"
#include "app.h"

extern t_errcode	menu_update(t_app *app)
{
	app->user_input = getch();
	if (app->user_input == ERR)
		return NO_ERROR;
	if (app->user_input == '\n'
		|| app->user_input == '\r'
		|| app->user_input == 'p' || app->user_input == 'P')
		app->current_view = &app->game_view;
	if (app->user_input == 27)
		app->state |= EXIT;
	if (app->user_input == KEY_LEFT && app->board.size > BOARD_MIN)
		app->board.size -= 1;
	if (app->user_input == KEY_RIGHT && app->board.size < BOARD_MAX)
		app->board.size += 1;
	if (app->user_input == 's' || app->user_input == 'S')
		app->current_view = &app->scores_view;
	return NO_ERROR;
}

static void	render_title(t_app *app, int y)
{
	print_centered(app, y + 0, " ___   ___  _  _  ___  ");
	print_centered(app, y + 1, "|__ \\ / _ \\| || ||__ \\ ");
	print_centered(app, y + 2, "   | | | | | || |_  | |");
	print_centered(app, y + 3, "  / /| | | |__   _|/ / ");
	print_centered(app, y + 4, " / /_| |_| |  | | / /_ ");
	print_centered(app, y + 5, "|____|\\___/   |_||____|");
}

static void	render_size_selector(t_app *app, int y)
{
	char	line[64];

	snprintf(line, sizeof(line), "<   %d   >", app->board.size);
	print_centered(app, y + 0, "- size -");
	print_centered(app, y + 1, line);
}

static void	render_play_button(t_app *app, int y)
{
	print_centered(app, y + 0, "                       ");
	attron(A_REVERSE | A_BOLD);
	print_centered(app, y + 1, "   PLAY (P)   ");
	print_centered(app, y + 3, "  SCORES (S)  ");
	attroff(A_REVERSE | A_BOLD);
	print_centered(app, y + 4, "                       ");
}

extern t_errcode	menu_render(t_app *app)
{
	if (!check_size(app))
		return NO_ERROR;
	int top = (app->screen.rows - 16) / 2;
	erase();
	render_frame(app, top + 1, 29, 17);
	render_title(app, top + 1);
	render_size_selector(app, top + 9);
	render_play_button(app, top + 11);
	refresh();
	return NO_ERROR;
}
