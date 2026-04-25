/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:38:23 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 12:36:39 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* intern imports */
#include "view.h"
#include "error.h"
#include "signals.h"
#include "render.h"

/* pour la boucle principale stabilisee a 60 fps */
/* bien essayer de separer temps / gameplay / display */

/* boucle principale */
/* calls input, gameplay, time, display */

/* en gros on anime ce qu'on doit animer et des que c'est fait
   on laisse le joueur jouer, et la on le reempeche et on fait nos trucs
   etc ...
*/

extern void game_loop(void) {
	t_view	menu_view = {.update = menu_update, .render = menu_render};
	t_view	game_view = {.update = game_update, .render = game_render};


	t_view	*current_view = &menu_view;
	(void)game_view;
	while (!must_exit())
	{
		if (must_resize())
			handle_resize();

		current_view->update();
		current_view->render();
	}
}
