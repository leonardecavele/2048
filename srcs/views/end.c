/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 19:55:24 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
#include <stdio.h>
/* intern */
#include "gameplay.h"
#include "app.h"
#include "libft.h"
#include "score.h"

static void	add_name_char(t_app *app, int ch)
{
	if (app->current_score_name_len >= 10)
		return ;
	app->current_score.name[app->current_score_name_len] = ch;
	app->current_score_name_len++;
	app->current_score.name[app->current_score_name_len] = '\0';
}

static void	remove_name_char(t_app *app)
{
	if (app->current_score_name_len <= 0)
		return ;
	app->current_score_name_len--;
	app->current_score.name[app->current_score_name_len] = '\0';
}

static t_errcode	handle_name_input(t_app *app)
{
	if (app->user_input == '\n'
		|| app->user_input == '\r'
		|| app->user_input == KEY_ENTER) {
		if (app->current_score_name_len > 0) {
			app->state &= ~NAME_INPUT;
			return save_score(app);
		}
		return NO_ERROR;
	}
	if (app->user_input == 27) {
		app->state &= ~NAME_INPUT;
		return NO_ERROR;
	}
	if (app->user_input == KEY_BACKSPACE
		|| app->user_input == 127
		|| app->user_input == '\b') {
		remove_name_char(app);
		return NO_ERROR;
	}
	if (ft_isalpha(app->user_input))
		add_name_char(app, ft_toupper(app->user_input));
	return NO_ERROR;
}

extern t_errcode	end_update(t_app *app)
{
	app->user_input = getch();
	if (app->user_input == ERR)
		return NO_ERROR;
	if (app->state & NAME_INPUT)
		return handle_name_input(app);
	if (app->user_input == 27)
		app->state |= EXIT;
	if (app->state & WIN
		&& !(app->state & SCORE_SAVED)
		&& (app->user_input == 's' || app->user_input == 'S')) {
		app->current_score_name_len = 0;
		app->current_score.name[0] = '\0';
		app->state |= NAME_INPUT;
		return NO_ERROR;
	}
	if (!(app->state & DEFEAT) && !(app->state & SCORE_SAVED)
		&& (app->user_input == 'c' || app->user_input == 'C'))
		app->current_view = &app->game_view;
	return NO_ERROR;
}

static void	render_gg(t_app *app, int y)
{
	attron(A_BOLD);
	print_centered(app, y + 0, "  ____    ____  ");
	print_centered(app, y + 1, " / ___|  / ___| ");
	print_centered(app, y + 2, "| |  _  | |  _  ");
	print_centered(app, y + 3, "| |_| | | |_| | ");
	print_centered(app, y + 4, " \\____|  \\____| ");
	attroff(A_BOLD);
}

static void	render_win(t_app *app, int y)
{
	attron(A_BOLD);
	print_centered(app, y + 0, "__        __ ___  _   _");
	print_centered(app, y + 1, " \\ \\      / ||_ _|| \\ | |");
	print_centered(app, y + 2, "  \\ \\ /\\ / /  | | |  \\| |");
	print_centered(app, y + 3, "   \\ V  V /   | | | |\\  |");
	print_centered(app, y + 4, "    \\_/\\_/   |___||_| \\_|");
	attroff(A_BOLD);
}

static void	render_defeat_title(t_app *app, int y)
{
	attron(A_BOLD);
	print_centered(app, y + 0, " ____  _____ _____ _____    _  _____");
	print_centered(app, y + 1, " |  _ \\| ____|  ___| ____|  / \\|_   _|");
	print_centered(app, y + 2, " | | | |  _| | |_  |  _|   / _ \\ | |  ");
	print_centered(app, y + 3, " | |_| | |___|  _| | |___ / ___ \\| |  ");
	print_centered(app, y + 4, " |____/|_____|_|   |_____/_/   \\_\\_|  ");
	attroff(A_BOLD);
}

static void	render_pause_title(t_app *app, int y)
{
	attron(A_BOLD);
	print_centered(app, y + 0, " ____   _   _   _ ____  _____ ");
	print_centered(app, y + 1, "|  _ \\ / \\ | | | / ___|| ____|");
	print_centered(app, y + 2, "| |_) / _ \\| | | \\___ \\|  _|  ");
	print_centered(app, y + 3, "|  __/ ___ \\ |_| |___) | |___ ");
	print_centered(app, y + 4, "|_| /_/   \\_\\___/|____/|_____|");
	attroff(A_BOLD);
}

static void	typing_score_name(char dst[11], const char *src)
{
	int	i = 0;

	for (; i < 10 && src[i] != '\0'; i++)
		dst[i] = src[i];
	for (; i < 10; i++)
		dst[i] = '_';
	dst[i] = '\0';
}

static void	render_name_input(t_app *app, int y)
{
	char	buffer[64];
	char	name[11];

	if (!(app->state & WIN))
		return ;
	if (app->state & SCORE_SAVED)
		snprintf(buffer, sizeof(buffer), "NAME : %s", app->current_score.name);
	else if (app->state & NAME_INPUT) {
		typing_score_name(name, app->current_score.name);
		snprintf(buffer, sizeof(buffer), "%s", name);
	}
	else
		snprintf(buffer, sizeof(buffer), "__________");
	attron(A_BOLD);
	print_centered(app, y, buffer);
	attroff(A_BOLD);
}

static void	render_score(t_app *app, int y)
{
	char	buffer[64];

	snprintf(buffer, sizeof(buffer), "SCORE : %ld", app->current_score.score);
	attron(A_BOLD);
	print_centered(app, y, buffer);
	attroff(A_BOLD);
}

static void	render_win_buttons(t_app *app, int y)
{
	attron(A_REVERSE | A_BOLD);
	if (!(app->state & SCORE_SAVED)) {
		print_centered(app, y + 0, " SAVE SCORE (S) ");
		print_centered(app, y + 2, "  CONTINUE (C)  ");
		print_centered(app, y + 4, "   EXIT (ESC)   ");
	}
	else
		print_centered(app, y + 0, "   EXIT (ESC)   ");
	attroff(A_REVERSE | A_BOLD);
}

static void	render_pause_buttons(t_app *app, int y)
{
	attron(A_REVERSE | A_BOLD);
	print_centered(app, y + 0, "  CONTINUE (C)  ");
	print_centered(app, y + 2, "   EXIT (ESC)   ");
	attroff(A_REVERSE | A_BOLD);
}

static void	render_defeat_buttons(t_app *app, int y)
{
	attron(A_REVERSE | A_BOLD);
	print_centered(app, y + 0, "   EXIT (ESC)   ");
	attroff(A_REVERSE | A_BOLD);
}

static void	render_defeat_screen(t_app *app)
{
	int top = (app->screen.rows - 12) / 2;
	render_frame(app, top, 40, 12);
	render_defeat_title(app, top);
	render_score(app, top + 7);
	render_defeat_buttons(app, top + 9);
}

static void	render_win_screen(t_app *app)
{
	int	box_height;
	int	box_width;

	box_height = 18;
	if (app->state & SCORE_SAVED)
		box_height -= 4;
	box_width = 22;
	if (app->state & END_MESSAGE_VER)
		box_width = 30;
	int top = (app->screen.rows - box_height) / 2;
	render_frame(app, top, box_width, box_height);
	if (app->state & END_MESSAGE_VER)
		render_win(app, top);
	else
		render_gg(app, top);
	render_score(app, top + 7);
	render_name_input(app, top + 9);
	render_win_buttons(app, top + 11);
}

static void	render_pause_screen(t_app *app)
{
	int top = (app->screen.rows - 14) / 2;
	render_frame(app, top, 34, 14);
	render_pause_title(app, top);
	render_score(app, top + 7);
	render_pause_buttons(app, top + 9);
}

extern t_errcode	end_render(t_app *app)
{
	erase();
	if (!check_size(app))
		return NO_ERROR;
	if (app->state & DEFEAT)
		render_defeat_screen(app);
	else if (app->state & WIN)
		render_win_screen(app);
	else
		render_pause_screen(app);
	refresh();
	return NO_ERROR;
}
