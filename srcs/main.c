/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 01:51:37 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 17:07:29 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
/* intern */
#include "error.h"
#include "render.h"
#include "signals.h"
#include "app_loop.h"


int	main(void)
{
	t_errcode errcode = NO_ERROR;

	errcode |= ncurses_init();
	if (errcode != NO_ERROR)
		return errcode_message(errcode);

	errcode |= signals_init();
	if (errcode == NO_ERROR) {
		srand(time(NULL));
		app_loop();
	}

	endwin();
	return errcode_message(errcode);
}
