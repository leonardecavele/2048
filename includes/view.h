/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:55:00 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 02:57:02 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
#define VIEW_H

/* comme ca on cree plusieurs views qui fournissent a la loop principale
   de maniere polymorphique les fonctions a appeler
*/
typedef struct s_view
{
	void (*update)(void);
	void (*render)(void);
}	t_view;

#endif
