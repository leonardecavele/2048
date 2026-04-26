/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:56:06 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 15:31:44 by ldecavel         ###   ########.fr       */
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

	bool		end_message_ver;

	/* state */
	bool		win;
	bool		exit;
	bool		defeat;

	/* score */
	t_score		scores[10];
	char		score_name[11];
	int64_t		score;
	int			score_name_len;
	bool		name_input;
	bool		score_saved;
}	t_app;

#endif
