/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:57:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 13:07:38 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern imports */
#include <ncurses.h>

/* intern imports */
#include "render.h"

extern void game_update(void)
{
	int c = getch();

	if (c == KEY_RESIZE) {
		handle_resize();
		return ;
	}

	if (c == KEY_UP) {
	}
	else if (c == KEY_DOWN) {
	}
	else if (c == KEY_LEFT) {
	}
	else if (c == KEY_RIGHT) {
	}
}

extern void game_render(void)
{
	/* affichage du jeu */
}
