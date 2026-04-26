#ifndef APP_H
#define APP_H

#include "view.h"
#include "gameplay.h"
#include "render.h"

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
