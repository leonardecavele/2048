/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:51:31 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 16:14:11 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

/* subject does not allow to edit this */
typedef enum e_const
{
	WIN_VALUE = 2048
}	t_const;
/* This value is taken into account only if it is a power of 2. (subject) */

# define MIN_BOARD_SIZE 4
# define MAX_BOARD_SIZE 16

# ifndef BOARD_SIZE 
#  define BOARD_SIZE 4
# elif (BOARD_SIZE < MIN_BOARD_SIZE) || (BOARD_SIZE > MAX_BOARD_SIZE)
#  undef BOARD_SIZE
#  define BOARD_SIZE 4
# endif


void	init_map(int board[BOARD_SIZE][BOARD_SIZE]);
void	add_one_nbr(int board[BOARD_SIZE][BOARD_SIZE]);
void	print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int 	positif_int_tab_len(int *tab);
void	move_down(int board[BOARD_SIZE][BOARD_SIZE]);
void	move_up(int board[BOARD_SIZE][BOARD_SIZE]);
void	move_left(int board[BOARD_SIZE][BOARD_SIZE]);
void	move_right(int board[BOARD_SIZE][BOARD_SIZE]);

#endif
