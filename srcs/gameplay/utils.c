/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:51:19 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 19:41:23 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"
#include "board.h"


int positif_int_tab_len(int *tab)
{
	int index;

	index = 0;
	while (tab[index] >= 0)
		index++;
	return (index);
}

void	init_combined(int combined[BOARD_MAX])
{
	int	i;

	i = 0;
	while (i < BOARD_MAX)
	{
		combined[i] = -1;
		i++;
	}
}
