/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:37:28 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 12:27:54 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
/* intern */
#include "error.h"
#include "render.h"

extern void handle_resize(void)
{
	endwin();
	refresh();
	clear();
}

extern t_errcode ncurses_init(void)
{
	if (initscr() == NULL
		|| cbreak() == ERR
		|| noecho() == ERR
		|| keypad(stdscr, TRUE) == ERR
		|| nodelay(stdscr, TRUE) == ERR)
		return NCURSES_ERROR;

	curs_set(0);
	if (has_colors() == TRUE) {
		start_color();
		use_default_colors();
	}

	refresh();
	return (NO_ERROR);
}
