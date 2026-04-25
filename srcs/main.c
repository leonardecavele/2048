/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 01:51:37 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 02:50:45 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
/* intern */
#include "error.h"


/* vu qu'on a un petit board on peut tout faire sur la stack */
/* pas besoin de malloc imo */
/* go mettre des defines pour la taille de la grid qu'on soit capable
   de gerer plus gros facilement
*/


/* vu qu'on a les signaux on peut gerer les ctrl c etc pour quand meme
   sortir proprement
*/


int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	/* use OR to update it with functions
	   errcode |= func();
	*/
	t_errcode errcode = NO_ERROR;

	/* init ncurses */
	/* init game */

	/* call game_loop */

	/* closes ncurses cleanly */

	return errcode_message(errcode);
}
