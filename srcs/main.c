/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 01:51:37 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 13:10:02 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
/* intern */
#include "error.h"
#include "render.h"
#include "signals.h"
#include "game_loop.h"


int	main(void)
{
	t_errcode errcode = NO_ERROR;

	errcode |= ncurses_init();
	if (errcode != NO_ERROR)
		return errcode_message(errcode);

	errcode |= signals_init();
	if (errcode == NO_ERROR)
	{
		/* init game */
		/* call game_loop */
		game_loop();
	}

	endwin();
	return errcode_message(errcode);
}
