/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:58:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 12:28:07 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern imports */
#include <ncurses.h>
/* intern imports */
#include "gameplay.h"
#include "app.h"
#include "libft.h"

static void	add_name_char(t_app *app, int ch)
{
	if (app->score_name_len >= 10)
		return ;
	app->score_name[app->score_name_len] = ch;
	app->score_name_len++;
	app->score_name[app->score_name_len] = '\0';
}

static void	remove_name_char(t_app *app)
{
	if (app->score_name_len <= 0)
		return ;
	app->score_name_len--;
	app->score_name[app->score_name_len] = '\0';
}

static t_errcode	save_score(t_app *app)
{
	FILE	*file;

	file = fopen("scores.dat", "a");
	if (file == NULL)
		return (FILE_ERROR);
	if (fprintf(file, "%s %ld\n", app->score_name, app->score) < 0) {
		fclose(file);
		return (FILE_ERROR);
	}
	if (fclose(file) == EOF)
		return (FILE_ERROR);
	app->score_saved = true;
	return (0);
}

static t_errcode	handle_name_input(t_app *app)
{
	if (app->user_input == '\n'
		|| app->user_input == '\r'
		|| app->user_input == KEY_ENTER) {
		if (app->score_name_len > 0) {
			app->name_input = false;
			return (save_score(app));
		}
		return (0);
	}
	if (app->user_input == 27) {
		app->name_input = false;
		return (0);
	}
	if (app->user_input == KEY_BACKSPACE
		|| app->user_input == 127
		|| app->user_input == '\b') {
		remove_name_char(app);
		return (0);
	}
	if (ft_isalpha(app->user_input))
		add_name_char(app, ft_toupper(app->user_input));
	return (0);
}

extern t_errcode	end_update(t_app *app)
{
	app->user_input = getch();

	if (app->user_input == ERR)
		return (NO_ERROR);

	if (app->name_input)
		return (handle_name_input(app));

	if (app->user_input == 27)
		app->exit = true;
	if (app->win == true
		&& app->score_saved == false
		&& (app->user_input == 's' || app->user_input == 'S')) {
		app->score_name_len = 0;
		app->score_name[0] = '\0';
		app->name_input = true;
		return (NO_ERROR);
	}
	if (!app->defeat
		&& (app->user_input == 'c' || app->user_input == 'C'))
		app->current_view = &app->game_view;

	return (NO_ERROR);
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

	if (app->win == false)
		return ;
	if (app->score_saved)
		snprintf(buffer, sizeof(buffer), "%s", app->score_name);
	else if (app->name_input) {
		char name[11];
		typing_score_name(name, app->score_name);
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

	snprintf(buffer, sizeof(buffer), "SCORE : %ld", app->score);
	attron(A_BOLD);
	print_centered(app, y, buffer);
	attroff(A_BOLD);
}

static void	render_win_buttons(t_app *app, int y)
{
	attron(A_REVERSE | A_BOLD);
	if (app->score_saved == false)
		print_centered(app, y + 0, " SAVE SCORE (S) ");
	print_centered(app, y + 2, "  CONTINUE (C)  ");
	print_centered(app, y + 4, "   EXIT (ESC)   ");
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

extern t_errcode end_render(t_app *app)
{
	check_size(app);

	int	r = app->screen.rows;

	erase();
	if (app->defeat == true) {
		render_defeat_title(app, (r / 2) - 5);
		render_frame(app, (r / 2) - 5, 41, 12);
		render_score(app, (r / 2) + 1);
		render_defeat_buttons(app, (r / 2) + 3);
	}
	else if (app->win == true) {
		if (app->end_message_ver) {
			render_win(app, (r / 2) - 6);
			render_frame(app, (r / 2) - 6, 30, 18);
		}
		else {
			render_gg(app, (r / 2) - 6);
			render_frame(app, (r / 2) - 6, 22, 18);
		}
		render_score(app, (r / 2));
		render_name_input(app, (r / 2) + 2);
		render_win_buttons(app, (r / 2) + 4);
	}
	else {
		render_pause_title(app, (r / 2) - 5);
		render_frame(app, (r / 2) - 5, 34, 14);
		render_score(app, (r / 2) + 1);
		render_pause_buttons(app, (r / 2) + 3);
	}
	refresh();

	return NO_ERROR;
}
