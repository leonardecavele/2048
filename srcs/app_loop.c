/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:38:23 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 17:08:06 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* intern imports */
#include "view.h"
#include "error.h"
#include "signals.h"
#include "render.h"
#include "app.h"

extern void app_loop(void) {
	t_app app = {
		.menu_view = {
			.update = menu_update, .render = menu_render
		},
		.game_view = {
			.update = game_update, .render = game_render
		},
		.end_view = {
			.update = end_update, .render = end_render
		},
		.user_input = -1
	};
	init_board(app.board);

	app.current_view = &app.menu_view;
	while (!must_exit() && app.user_input != 27)
	{
		if (must_resize())
			handle_resize();

		app.current_view->update(&app);
		app.current_view->render(&app);
	}
}
