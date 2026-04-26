/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:51:31 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 13:16:45 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stdint.h>
#include "app.h"

void	init_board(t_cell board[BOARD_SIZE][BOARD_SIZE]);
void	add_one_nbr(t_cell board[BOARD_SIZE][BOARD_SIZE]);
void	prt_cell_board(int board[BOARD_SIZE][BOARD_SIZE]);
int 	positif_int_tab_len(int *tab);
int		move_down(t_app *app);
int		move_up(t_app *app);
int		move_left(t_app *app);
int		move_right(t_app *app);
int		are_you_winning_son(t_cell board[BOARD_SIZE][BOARD_SIZE]);
int		is_loosed(t_cell board[BOARD_SIZE][BOARD_SIZE]);

#endif
