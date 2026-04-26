/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:56:06 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 13:50:54 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
#define APP_H

#include "view.h"
#include "render.h"
#include "gameplay.h"
#include <stdint.h>
#include <stdbool.h>


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
