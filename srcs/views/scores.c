/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 16:35:55 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
/* intern */
#include "gameplay.h"
#include "app.h"

extern t_errcode scores_update(t_app *app)
{
	app->user_input = getch();

	if (app->user_input == ERR)
		return NO_ERROR;

	if (app->user_input == 27)
		app->current_view = &app->menu_view;

	return NO_ERROR;
}

static void	render_title(t_app *app, int y)
{
	print_centered(app, y + 0, " ____   ____ ___  ____  _____ ____  ");
	print_centered(app, y + 1, "/ ___| / ___/ _ \\|  _ \\| ____/ ___| ");
	print_centered(app, y + 2, "| |__ | |  | | | | |_) | |_  | |__  ");
	print_centered(app, y + 3, "\\___ \\| |  | | | |  _ <|  _| \\___ \\ ");
	print_centered(app, y + 4, " ___| | |__| |_| | | | | |___ ___| |");
	print_centered(app, y + 5, "|____/ \\____\\___/|_| \\_\\_____|____/ ");
}

static void	render_play_button(t_app *app, int y)
{
	print_centered(app, y + 7, "                       ");
	attron(A_REVERSE | A_BOLD);
	print_centered(app, y + 8, "   MENU (ESC)   ");
	attroff(A_REVERSE | A_BOLD);
	print_centered(app, y + 9, "                       ");
}

static void	render_scores(t_app *app, int y)
{
	char	line[64];

	for (int i = 0; i < 10; i++) {
		snprintf(
			line, sizeof(line), "%2d. %-9s %ld",
			i + 1, app->scores[i].name, app->scores[i].score
		);
		print_centered(app, y + i, line);
	}
}

extern t_errcode scores_render(t_app *app)
{
	check_size(app);

	int r = app->screen.rows;

	erase();
	render_title(app, (r / 2) - 5);
	render_frame(app, (r / 2) - 5, 40, 22);
	render_scores(app, (r / 2) + 2);
	render_play_button(app, (r / 2) + 5);
	refresh();

	return NO_ERROR;
}
