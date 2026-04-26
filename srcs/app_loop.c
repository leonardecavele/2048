/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:38:23 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 12:25:51 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <stdlib.h>
/* intern */
#include "view.h"
#include "error.h"
#include "signals.h"
#include "render.h"
#include "app.h"

extern t_errcode app_loop(void) {
	t_errcode errcode = NO_ERROR;

	t_app app = {
		.menu_view = {
			.update = menu_update,
			.render = menu_render
		},
		.game_view = {
			.update = game_update,
			.render = game_render
		},
		.end_view = {
			.update = end_update,
			.render = end_render
		},
		.user_input = -1,
		.end_message_ver = rand() % 2 == 0
	};
	init_board(app.board);

	app.current_view = &app.menu_view;
	while (!must_exit() && !app.exit) {
		if (must_resize())
			handle_resize();

		errcode |= app.current_view->update(&app);
		if (errcode != NO_ERROR)
			return errcode;
		errcode |= app.current_view->render(&app);
		if (errcode != NO_ERROR)
			return errcode;
	}
	return errcode;
}
