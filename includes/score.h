/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:21:50 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 16:12:35 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORE_H
#define SCORE_H

#include <stdint.h>
#include "error.h"

#define SCORE_FILE_NAME "scores.dat"
#define DEFAULT_SCORE -42
#define DEFAULT_NAME "UNKNOWN"

typedef struct s_app t_app;

typedef struct s_score {
	int64_t score;
	char name[11];
}	t_score;

t_errcode parse_scores(t_app *app);
t_errcode save_score(t_app *app);
void init_scores(t_app *app);

#endif
