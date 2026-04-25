/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 01:51:37 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 12:43:25 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
/* intern */
#include "error.h"
#include "render.h"
#include "signals.h"


#include <unistd.h>

/* vu qu'on a un petit board on peut tout faire sur la stack */
/* pas besoin de malloc imo */
/* go mettre des defines pour la taille de la grid qu'on soit capable
   de gerer plus gros facilement
*/


/* vu qu'on a les signaux on peut gerer les ctrl c etc pour quand meme
   sortir proprement
*/


int	main(void)
{
	t_errcode errcode = NO_ERROR;

	errcode |= ncurses_init();
	errcode |= signals_init();
	if (errcode != NO_ERROR)
		return (errcode_message(errcode));

	/* init game */

	sleep(5);

	/* call game_loop */

	/* closes ncurses cleanly */

	endwin();
	return errcode_message(errcode);
}
