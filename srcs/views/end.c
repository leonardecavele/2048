/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 17:32:36 by ldecavel         ###   ########.fr       */
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

	if (app->user_input == '\n'
		|| app->user_input == '\r'
		|| app->user_input == KEY_ENTER)
		app->user_input = 27;
}

extern void end_render(t_app *app)
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
	
	/* render func */
}
