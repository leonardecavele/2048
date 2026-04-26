/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:56:06 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 13:03:41 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
#define APP_H

#include "view.h"
#include "render.h"
#include <stdint.h>
#include <stdbool.h>

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
#  define BOARD_SIZE 4
# elif (BOARD_SIZE < MIN_BOARD_SIZE) || (BOARD_SIZE > MAX_BOARD_SIZE)
#  undef BOARD_SIZE
#  define BOARD_SIZE 4
# endif


typedef struct s_app
{
	t_cell		board[BOARD_SIZE][BOARD_SIZE];
	t_view		menu_view;
	t_view		game_view;
	t_view		end_view;
	t_view		*current_view;
	t_screen	screen;
	int64_t		score;
	int			user_input;
	bool		exit;
	bool		end_message_ver;
	bool		win;
	bool		defeat;
	char		score_name[11];
	int			score_name_len;
	bool		name_input;
	bool		score_saved;
}	t_app;

#endif
