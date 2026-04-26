/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 17:18:15 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
#include <stdio.h>
/* intern */
#include "gameplay.h"
#include "app.h"

extern t_errcode	scores_update(t_app *app)
{
	app->user_input = getch();

	if (app->user_input == ERR)
		return (NO_ERROR);
	if (app->user_input == 27)
		app->current_view = &app->menu_view;
	return (NO_ERROR);
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
	print_centered(app, y + 0, "                       ");
	attron(A_REVERSE | A_BOLD);
	print_centered(app, y + 1, "   MENU (ESC)   ");
	attroff(A_REVERSE | A_BOLD);
	print_centered(app, y + 2, "                       ");
}

static void	render_scores(t_app *app, int y)
{
	char line[64];
	int order[10];

	for (int i = 0; i < 10; i++)
		order[i] = i;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (app->scores[order[j]].score < app->scores[order[j + 1]].score) {
				int tmp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		snprintf(
			line, sizeof(line), "%s: %ld",
			app->scores[order[i]].name,
			app->scores[order[i]].score
		);
		print_centered(app, y + i, line);
	}
}

extern t_errcode	scores_render(t_app *app)
{
	int	top;

	if (!check_size(app))
		return (NO_ERROR);
	top = (app->screen.rows - 22) / 2;
	erase();
	render_frame(app, top + 1, 40, 22);
	render_title(app, top + 1);
	render_scores(app, top + 8);
	render_play_button(app, top + 18);
	refresh();
	return (NO_ERROR);
}
