/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:57:35 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 16:43:02 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "font.h"

void	init_font(t_font *f)
{
	f->numbers[0].lines[0] = "######";
	f->numbers[0].lines[1] = "#    #";
	f->numbers[0].lines[2] = "#    #";
	f->numbers[0].lines[3] = "#    #";
	f->numbers[0].lines[4] = "######";

	f->numbers[1].lines[0] = "  ##  ";
	f->numbers[1].lines[1] = "####  ";
	f->numbers[1].lines[2] = "  ##  ";
	f->numbers[1].lines[3] = "  ##  ";
	f->numbers[1].lines[4] = "######";

	f->numbers[2].lines[0] = "######";
	f->numbers[2].lines[1] = "     #";
	f->numbers[2].lines[2] = "######";
	f->numbers[2].lines[3] = "#     ";
	f->numbers[2].lines[4] = "######";

	f->numbers[3].lines[0] = "######";
	f->numbers[3].lines[1] = "     #";
	f->numbers[3].lines[2] = " #####";
	f->numbers[3].lines[3] = "     #";
	f->numbers[3].lines[4] = "######";

	f->numbers[4].lines[0] = "#    #";
	f->numbers[4].lines[1] = "#    #";
	f->numbers[4].lines[2] = "######";
	f->numbers[4].lines[3] = "     #";
	f->numbers[4].lines[4] = "     #";

	f->numbers[5].lines[0] = "######";
	f->numbers[5].lines[1] = "#     ";
	f->numbers[5].lines[2] = "######";
	f->numbers[5].lines[3] = "     #";
	f->numbers[5].lines[4] = "######";

	f->numbers[6].lines[0] = "######";
	f->numbers[6].lines[1] = "#     ";
	f->numbers[6].lines[2] = "######";
	f->numbers[6].lines[3] = "#    #";
	f->numbers[6].lines[4] = "######";

	f->numbers[7].lines[0] = "######";
	f->numbers[7].lines[1] = "    # ";
	f->numbers[7].lines[2] = "   #  ";
	f->numbers[7].lines[3] = "  #   ";
	f->numbers[7].lines[4] = " #    ";

	f->numbers[8].lines[0] = "######";
	f->numbers[8].lines[1] = "#    #";
	f->numbers[8].lines[2] = "######";
	f->numbers[8].lines[3] = "#    #";
	f->numbers[8].lines[4] = "######";

	f->numbers[9].lines[0] = "######";
	f->numbers[9].lines[1] = "#    #";
	f->numbers[9].lines[2] = "######";
	f->numbers[9].lines[3] = "     #";
	f->numbers[9].lines[4] = "######";
}

static void	draw_ascii_digit(int digit, int start_y, int start_x)
{
	static t_font	font = {0};
	static int		is_init = 0;
	int 			i;

	if (!is_init)
	{
		init_font(&font);
		is_init = 1;
	}
	i = 0;
	while (i < ART_HEIGHT)
	{
		mvprintw(start_y + i, start_x, "%s", font.numbers[digit].lines[i]);
		i++;
	}
}

int	draw_ascii_value(int value, int center_y, int center_x, int cell_h, int cell_w)
{
	char	str[12];
	int		len;
	int		total_width;
	int		start_x;
	int		i;

	sprintf(str, "%d", value);
	len = 0;
	while (str[len])
		len++;

	total_width = len * ART_WIDTH;
	if (cell_h <= ART_HEIGHT || cell_w <= total_width)
		return (1);
	start_x = center_x - (total_width / 2) + 1;
	int start_y = center_y - (5 / 2); 

	i = 0;
	while (str[i])
	{
		draw_ascii_digit(str[i] - '0', start_y, start_x + (i * ART_WIDTH));
		i++;
	}
	return (0);
}
