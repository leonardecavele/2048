/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 16:40:29 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
/* intern */
#include "gameplay.h"
#include "app.h"

extern t_errcode menu_update(t_app *app)
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

	if (app->user_input == 's' || app->user_input == 'S')
		app->current_view = &app->scores_view;

	return NO_ERROR;
}

static void render_title(t_app *app, int y)
{
	print_centered(app, y + 0,  " ___   ___  _  _  ___  ");
	print_centered(app, y + 1,  "|__ \\ / _ \\| || ||__ \\ ");
	print_centered(app, y + 2,  "   | | | | | || |_  | |");
	print_centered(app, y + 3,  "  / /| | | |__   _|/ / ");
	print_centered(app, y + 4,  " / /_| |_| |  | | / /_ ");
	print_centered(app, y + 5,  "|____|\\___/   |_||____|");
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


extern t_errcode menu_render(t_app *app)
{
	if (!check_size(app))
		return NO_ERROR;

	int r = app->screen.rows;

	erase();
	render_frame(app, (r / 2) - 5, 29, 14);
	render_title(app, (r / 2) - 5);
	render_play_button(app, (r / 2) - 5);
	refresh();

	return NO_ERROR;
}
