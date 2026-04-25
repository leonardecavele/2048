/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:01:36 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 13:32:32 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include "libft.h"
/* intern */
#include "error.h"

/* usage */
static void	usage(void)
{
	ft_dprintf(
		2,
		"Usage:\n"
		"  ./2048\n"
		"\n"
		"Controls:\n"
		"  Arrow Up     move tiles up\n"
		"  Arrow Down   move tiles down\n"
		"  Arrow Left   move tiles left\n"
		"  Arrow Right  move tiles right\n"
		"  ESCAPE       quit the game properly\n"
		"\n"
		"Goal:\n"
		"  Reach 2048, or continue playing after victory.\n"
	);
}

/* prints context about the errorcode */
extern t_errcode	errcode_message(t_errcode errcode)
{
	if (errcode & ARG_COUNT_ERROR
		|| errcode & INVALID_ARG_ERROR) {
		usage();
		return (errcode);
	}

	if (errcode & NCURSES_ERROR)
		ft_dprintf(2, "cannot init ncurses\n");
	if (errcode & SIGNAL_ERROR)
		ft_dprintf(2, "error with signals\n");
	return (errcode);
}
