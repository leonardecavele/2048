/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 16:58:32 by ldecavel         ###   ########.fr       */
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
		|| app->user_input == KEY_ENTER)
		app->current_view = &app->game_view;
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
	print_centered(app, y - 1, "              ");
	attron(A_REVERSE | A_BOLD);
	print_centered(app, y + 0, "     PLAY     ");
	attroff(A_REVERSE | A_BOLD);
	print_centered(app, y + 1, "              ");
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

	render_title(app, r / 5);
	render_play_button(app, (r / 5) * 3.5);
}
