/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:37:28 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 18:25:22 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <ncurses.h>
/* intern */
#include "error.h"
#include "render.h"
#include "libft.h"
#include "app.h"
#include "helpers.h"

extern void handle_resize(void)
{
	endwin();
	refresh();
	clear();
}

extern t_errcode ncurses_init(void)
{
	if (initscr() == NULL
		|| cbreak() == ERR
		|| noecho() == ERR
		|| keypad(stdscr, TRUE) == ERR
		|| nodelay(stdscr, FALSE) == ERR)
		return NCURSES_ERROR;

	curs_set(0);
	set_escdelay(25);
	timeout(16);

	if (has_colors() == TRUE) {
		start_color();
		use_default_colors();

		if (can_change_color())
		{
			init_color(8,  933, 894, 855);   // #eee4da - tile 2 (beige)
			init_color(9,  929, 878, 784);   // #ede0c8 - tile 4 (tan)
			init_color(10, 949, 694, 474);   // #f2b179 - tile 8 (orange)
			init_color(11, 960, 584, 388);   // #f59563 - tile 16 (dark orange)
			init_color(12, 965, 486, 373);   // #f67c5f - tile 32 (red-orange)
			init_color(13, 949, 368, 231);   // #f65e3b - tile 64 (red)
			init_color(14, 929, 812, 478);   // #edcf72 - tile 128 (gold)
			init_color(15, 929, 800, 380);   // #edcc61 - tile 256 (golden)
			init_color(16, 929, 784, 235);   // #edc850 - tile 512 (yellow-gold)
			init_color(17, 929, 776, 149);   // #edc53f - tile 1024 (bright gold)
			init_color(18, 929, 765, 71);    // #edc22e - tile 2048 (victory gold)
			init_color(19, 60,  58,  51);    // #3c3a32 - tile 4096+ (dark)
			
			// Initialize color pairs with custom colors
			// Format: init_pair(pair_number, foreground, background)
			init_pair(1, 0, 8);    // 2: dark text on beige
			init_pair(2, 0, 9);    // 4: dark text on tan
			init_pair(3, 0, 10);   // 8: white text on orange
			init_pair(4, 0, 11);   // 16: white text on dark orange
			init_pair(5, 0, 12);   // 32: white text on red-orange
			init_pair(6, 0, 13);   // 64: white text on red
			init_pair(7, 0, 14);   // 128: white text on gold
			init_pair(8, 0, 15);   // 256: white text on golden
			init_pair(9, 0, 16);   // 512: white text on yellow-gold
			init_pair(10, 0, 17);  // 1024: white text on bright gold
			init_pair(11, 0, 18);  // 2048: white text on victory gold
			init_pair(12, 0, 19);  // 4096+: white text on dark
			init_pair(13, 0, 19);  // Higher: white text on dark
		}
		else
		{
			// Fallback to basic colors if terminal doesn't support color changes
			init_pair(1, COLOR_BLACK, COLOR_WHITE);
			init_pair(2, COLOR_BLACK, COLOR_YELLOW);
			init_pair(3, COLOR_BLACK, COLOR_YELLOW);
			init_pair(4, COLOR_BLACK, COLOR_RED);
			init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
			init_pair(6, COLOR_BLACK, COLOR_RED);
			init_pair(7, COLOR_BLACK, COLOR_CYAN);
			init_pair(8, COLOR_BLACK, COLOR_GREEN);
			init_pair(9, COLOR_BLACK, COLOR_CYAN);
			init_pair(10, COLOR_BLACK, COLOR_GREEN);
			init_pair(11, COLOR_BLACK, COLOR_MAGENTA);
			init_pair(12, COLOR_BLACK, COLOR_BLUE);
			init_pair(13, COLOR_BLACK, COLOR_BLACK);
		}
	}

	refresh();
	return (NO_ERROR);
}

extern void print_centered(t_app *app, int y, const char *str)
{
	int c = app->screen.cols;
	int x = max(0, (c - (int)ft_strlen(str)) / 2);

	mvprintw(y, x, "%s", str);
}

extern void render_too_small(t_app *app)
{
	int r = app->screen.rows;
	int c = app->screen.cols;

	(void)c;
	print_centered(app, r / 2, "Windows too small, please increase size");
}

extern void render_frame(t_app *app, int y, int box_w, int box_h)
{
	int start_y = y - 1;
	int start_x = (app->screen.cols - box_w) / 2;

	attron(A_BOLD);
	mvaddch(start_y, start_x, ACS_ULCORNER);
	mvhline(start_y, start_x + 1, ACS_HLINE, box_w - 2);
	mvaddch(start_y, start_x + box_w - 1, ACS_URCORNER);

	for (int i = 1; i < box_h - 1; i++) {
		mvaddch(start_y + i, start_x, ACS_VLINE);
		mvaddch(start_y + i, start_x + box_w - 1, ACS_VLINE);
	}

	mvaddch(start_y + box_h - 1, start_x, ACS_LLCORNER);
	mvhline(start_y + box_h - 1, start_x + 1, ACS_HLINE, box_w - 2);
	mvaddch(start_y + box_h - 1, start_x + box_w - 1, ACS_LRCORNER);
	attroff(A_BOLD);
}

extern bool check_size(t_app *app)
{
	getmaxyx(stdscr, app->screen.rows, app->screen.cols);

	int r = app->screen.rows;
	int c = app->screen.cols;

	if (r < MIN_ROW || c < MIN_COL) {
		render_too_small(app);
		return false;
	}

	return true;
}

extern bool check_size_board(t_app *app)
{
	getmaxyx(stdscr, app->screen.rows, app->screen.cols);

	int r = app->screen.rows;
	int c = app->screen.cols;

	if ((r - 1 < app->board.size * 6) || (c - 1 < app->board.size * 6)) {
		render_too_small(app);
		return false;
	}

	return true;
}
