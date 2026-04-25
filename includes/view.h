/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:55:00 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 13:43:14 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
#define VIEW_H

typedef struct s_app t_app;

typedef struct s_view
{
	void (*update)(t_app *app);
	void (*render)(t_app *app);
}	t_view;

/* game */
void game_update(t_app *app);
void game_render(t_app *app);

/* menu */
void menu_update(t_app *app);
void menu_render(t_app *app);

#endif
