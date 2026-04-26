/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:21:02 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 14:34:52 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* intern */
#include "error.h"
#include "app.h"

static t_errcode	fetch_score(t_app *app)
{
	FILE *file = fopen("scores.dat", "r");
	if (file == NULL)
		return (FILE_ERROR);

	char line[256];
	char key[64];
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (sscanf(line, "%63s %d", key, &value) == 2)
			printf("key = %s, value = %d\n", key, value);
		else
			printf("ligne invalide: %s", line);
	}

	if (fclose(file) == EOF)
		return (FILE_ERROR);
	return (NO_ERROR);
}


extern t_errcode parse_scores(t_app *app)
{
	return NO_ERROR;
}
