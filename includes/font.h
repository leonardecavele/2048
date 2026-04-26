/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:56:50 by gabach            #+#    #+#             */
/*   Updated: 2026/04/26 16:34:27 by gabach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
# define FONT_H

#define ART_HEIGHT 5
#define ART_WIDTH 7

typedef struct s_number_art
{
	char	*lines[ART_HEIGHT];
}	t_number_art;

typedef struct s_font
{
	t_number_art	numbers[10];
}	t_font;

int	draw_ascii_value(int value, int center_y, int center_x, int cell_h, int cell_w);

#endif
