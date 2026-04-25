#ifndef APP_H
#define APP_H

#include "view.h"
#include "gameplay.h"

typedef struct s_app
{
	t_cell	board[BOARD_SIZE][BOARD_SIZE];
	t_view	menu_view;
	t_view	game_view;
	t_view	*current_view;
}	t_app;

#endif
