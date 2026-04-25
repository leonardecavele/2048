/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 22:34:55 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern imports */
#include <ncurses.h>
/* intern imports */
#include "gameplay.h"
#include "app.h"

extern void end_update(t_app *app)
{
	app->user_input = getch();

	if (app->user_input == ERR)
		return ;

	if (app->user_input == 27)
		app->exit = true;

	if (!app->defeat
		&& (app->user_input == 'c' || app->user_input == 'C'))
		app->current_view = &app->game_view;
}

static void	render_gg(t_app *app, int y)
{
	attron(A_BOLD);
	print_centered(app, y + 0, "  ____    ____  ");
	print_centered(app, y + 1, " / ___|  / ___| ");
	print_centered(app, y + 2, "| |  _  | |  _  ");
	print_centered(app, y + 3, "| |_| | | |_| | ");
	print_centered(app, y + 4, " \\____|  \\____| ");
	attroff(A_BOLD);
}

static void	render_win(t_app *app, int y)
{
	attron(A_BOLD);
	print_centered(app, y + 0, "__        __ ___  _   _");
	print_centered(app, y + 1, " \\ \\      / ||_ _|| \\ | |");
	print_centered(app, y + 2, "  \\ \\ /\\ / /  | | |  \\| |");
	print_centered(app, y + 3, "   \\ V  V /   | | | |\\  |");
	print_centered(app, y + 4, "    \\_/\\_/   |___||_| \\_|");
	attroff(A_BOLD);
}

static void	render_defeat_title(t_app *app, int y)
{
	attron(A_BOLD);
	print_centered(app, y + 0, " ____  _____ _____ _____    _  _____");
	print_centered(app, y + 1, " |  _ \\| ____|  ___| ____|  / \\|_   _|");
	print_centered(app, y + 2, " | | | |  _| | |_  |  _|   / _ \\ | |  ");
	print_centered(app, y + 3, " | |_| | |___|  _| | |___ / ___ \\| |  ");
	print_centered(app, y + 4, " |____/|_____|_|   |_____/_/   \\_\\_|  ");
	attroff(A_BOLD);
}

static void	render_pause_title(t_app *app, int y)
{
	attron(A_BOLD);
	print_centered(app, y + 0, "   ____   _   _   _ ____  _____ ");
	print_centered(app, y + 1, "  |  _ \\ / \\ | | | / ___|| ____|");
	print_centered(app, y + 2, "  | |_) / _ \\| | | \\___ \\|  _|  ");
	print_centered(app, y + 3, "  |  __/ ___ \\ |_| |___) | |___ ");
	print_centered(app, y + 4, "  |_| /_/   \\_\\___/|____/|_____|");
	attroff(A_BOLD);
}

static void	render_score(t_app *app, int y)
{
	char	buffer[64];

	snprintf(buffer, sizeof(buffer), "SCORE : %ld", app->score);
	attron(A_BOLD);
	print_centered(app, y, buffer);
	attroff(A_BOLD);
}

static void	render_end_buttons(t_app *app, int y)
{
	attron(A_REVERSE | A_BOLD);
	if (!app->defeat) {
		print_centered(app, y + 0, "  CONTINUE (C)  ");
		print_centered(app, y + 2, "   EXIT (ESC)   ");
	}
	else
		print_centered(app, y + 0, "   EXIT (ESC)   ");
	attroff(A_REVERSE | A_BOLD);
}

extern void end_render(t_app *app)
{
	check_size(app);

	int r = app->screen.rows;

	erase();

	if (app->win == true) {
		render_frame(app, (r / 2) - 5, 31, 14);
		if (app->end_message_ver)
			render_win(app, (r / 2) - 5);
		else
			render_gg(app, (r / 2) - 5);
	}
	else if (app->defeat == true) {
		render_frame(app, (r / 2) - 5, 41, 12);
		render_defeat_title(app, (r / 2) - 5);
	}
	else {
		render_pause_title(app, (r / 2) - 5);
		render_frame(app, (r / 2) - 5, 34, 14);
	}

	render_score(app, (r / 2) + 1);
	render_end_buttons(app, (r / 2) + 3);
	refresh();
}
