/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 01:51:37 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 12:38:38 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
/* intern */
#include "error.h"
#include "gameplay.h"
#include "libft.h"


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
	int	board[BOARD_SIZE][BOARD_SIZE];

	(void)ac;
	(void)av;
	/* use OR to update it with functions
	   errcode |= func();
	*/
	srand(time(NULL));
	t_errcode errcode = NO_ERROR;

	init_map(board);
	print_board(board);
	ft_putchar_fd('\n', 1);
	add_one_nbr(board);
	print_board(board);

	/* init ncurses */
	/* init game */

	/* call game_loop */

	/* closes ncurses cleanly */

	return errcode_message(errcode);
}
