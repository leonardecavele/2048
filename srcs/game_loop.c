/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:38:23 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 13:06:49 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* intern imports */
#include "view.h"
#include "error.h"
#include "signals.h"
#include "render.h"

extern void game_loop(void) {
	t_view	menu_view = {.update = menu_update, .render = menu_render};
	t_view	game_view = {.update = game_update, .render = game_render};


	t_view	*current_view = &game_view;
	(void)menu_view;

	while (!must_exit())
	{
		if (must_resize())
			handle_resize();

		current_view->update();
		current_view->render();
	}
}
