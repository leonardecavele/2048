/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:56:06 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 15:37:53 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
#define APP_H

#include "view.h"
#include "render.h"
#include "gameplay.h"
#include <stdint.h>
#include <stdbool.h>
#include "score.h"

typedef enum e_state {
	WIN = (1 << 0),
	EXIT = (1 << 1),
	DEFEAT = (1 << 2),
	NAME_INPUT = (1 << 3),
	SCORE_SAVED = (1 << 4),
	END_MESSAGE_VER = (1 << 5)
}	t_state;

/* do other structures */
typedef struct s_app
{
	t_cell		board[BOARD_SIZE][BOARD_SIZE];
	t_view		menu_view;
	t_view		game_view;
	t_view		end_view;
	t_view		*current_view;
	t_screen	screen;
	int			user_input;
	int64_t		state;
	t_score		scores[10];
	t_score		current_score;
	int			current_score_name_len;
}	t_app;

#endif
