/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:04:09 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 17:34:54 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
#define BOARD_H

#define BOARD_MIN 4
#define BOARD_MAX 16

#include <stdint.h>

typedef uint32_t t_cell;

typedef struct s_board
{
	int size;
	int last_modif;
	t_cell	board[BOARD_MAX][BOARD_MAX];
}	t_board;

void	init_board(t_board *board);
void	add_one_nbr(t_board *board);
int		are_you_winning_son(t_board *board);
int		is_loosed(t_board *board);

#endif
