/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:38:23 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 02:44:41 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* pour la boucle principale stabilisee a 60 fps */
/* bien essayer de separer temps / gameplay / display */

/* boucle principale */
/* calls input, gameplay, time, display */

/* en gros on anime ce qu'on doit animer et des que c'est fait
   on laisse le joueur jouer, et la on le reempeche et on fait nos trucs
   etc ...
*/
