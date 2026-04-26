/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:04:09 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 14:13:57 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
#define BOARD_H

#define BOARD_MIN 4
#define BOARD_MAX 16

typedef struct s_board
{
	int size;
	int	board[BOARD_MAX][BOARD_MAX];
}	t_board;

void	init_board(t_board *board);
void	add_one_nbr(t_board *board);
void	prt_cell_board(t_board *board);
int		are_you_winning_son(t_board *board);
int		is_loosed(t_board *board);

#endif
