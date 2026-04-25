/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:21:20 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 21:55:29 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

#include "error.h"

#define TERM_CHAR_RATIO			2

#define MAX_WIDTH_RATIO_NUM		16
#define MAX_WIDTH_RATIO_DEN		10

#define MIN_WIDTH_RATIO_NUM		18
#define MIN_WIDTH_RATIO_DEN		10

#define MIN_COL 42
#define MIN_ROW 21

typedef struct s_app t_app;

typedef struct s_screen {
	int rows;
	int cols;
}	t_screen;

t_errcode ncurses_init(void);
void handle_resize(void);
void render_too_small(t_app *app);
void render_invalid_ratio(t_app *app);
void print_centered(t_app *app, int y, const char *str);
bool screen_ratio_is_bad(t_app *app);
void render_frame(t_app *app, int y, int box_w, int box_h);

#endif
