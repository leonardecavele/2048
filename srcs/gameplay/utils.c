/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:51:19 by gabach            #+#    #+#             */
/*   Updated: 2026/04/25 12:51:49 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"
#include "libft.h"


int positif_int_tab_len(int *tab)
{
	int index;

	index = 0;
	while (tab[index] >= 0)
		index++;
	return (index);
}

void	print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
	int row;
	int col;

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			ft_putnbr_fd(board[row][col], 1);
			ft_putchar_fd(' ', 1);
			col++;
		}
		ft_putchar_fd('\n', 1);
		row++;
	}
}

