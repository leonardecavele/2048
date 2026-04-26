/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:56:06 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 14:08:32 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
#define APP_H

/* extern */
#include <stdint.h>
#include <stdbool.h>

/* intern */
#include "view.h"
#include "render.h"
#include "gameplay.h"
#include "board.h"

typedef struct s_app
{
	t_board		board;
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
