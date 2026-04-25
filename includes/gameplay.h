/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:51:31 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 14:06:56 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stdint.h>

/* subject does not allow to edit this */
typedef enum e_const
{
	WIN_VALUE = 2048
}	t_const;
/* This value is taken into account only if it is a power of 2. (subject) */

typedef uint32_t t_cell;

# define MIN_BOARD_SIZE 4
# define MAX_BOARD_SIZE 16

# ifndef BOARD_SIZE 
#  define BOARD_SIZE 10
# elif (BOARD_SIZE < MIN_BOARD_SIZE) || (BOARD_SIZE > MAX_BOARD_SIZE)
#  undef BOARD_SIZE
#  define BOARD_SIZE 4
# endif

void	init_board(t_cell board[BOARD_SIZE][BOARD_SIZE]);
void	add_one_nbr(t_cell board[BOARD_SIZE][BOARD_SIZE]);
void	print_board(t_cell board[BOARD_SIZE][BOARD_SIZE]);

#endif
