/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:55:00 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 16:18:24 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
#define VIEW_H

#include "error.h"

typedef struct s_app t_app;

typedef struct s_view
{
	t_errcode (*update)(t_app *app);
	t_errcode (*render)(t_app *app);
}	t_view;

/* menu */
t_errcode menu_update(t_app *app);
t_errcode menu_render(t_app *app);

/* scores */
t_errcode scores_update(t_app *app);
t_errcode scores_render(t_app *app);

/* game */
t_errcode game_update(t_app *app);
t_errcode game_render(t_app *app);

/* end */
t_errcode end_update(t_app *app);
t_errcode end_render(t_app *app);

#endif
