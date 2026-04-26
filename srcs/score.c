/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:21:02 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/26 16:14:32 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <stdio.h>
#include <errno.h>

/* intern */
#include "error.h"
#include "app.h"
#include "score.h"

static int get_worst_index(t_app *app)
{
	int	worst_index = 0;

	for (int i = 0; i < 10; i++) {
		if (app->scores[i].score < app->scores[worst_index].score)
			worst_index = i;
	}
	return worst_index;
}

static t_errcode write_scores(t_app *app)
{
	FILE *file = fopen(SCORE_FILE_NAME, "w");
	if (file == NULL)
		return FILE_ERROR;

	for (int i = 0; i < 10; i++) {
		if (fprintf(file, "%s %ld\n",
				app->scores[i].name,
				app->scores[i].score) < 0) {
			fclose(file);
			return FILE_ERROR;
		}
	}

	if (fclose(file) == EOF)
		return FILE_ERROR;
	return NO_ERROR;
}

extern t_errcode save_score(t_app *app)
{
	int worst_index = get_worst_index(app);

	if (app->current_score.score <= app->scores[worst_index].score) {
		app->state |= SCORE_SAVED;
		return NO_ERROR;
	}

	snprintf(
		app->scores[worst_index].name,
		sizeof(app->scores[worst_index].name),
		"%s", app->current_score.name
	);
	app->scores[worst_index].score = app->current_score.score;

	t_errcode errcode = write_scores(app);
	if (errcode != NO_ERROR)
		return errcode;

	app->state |= SCORE_SAVED;
	return NO_ERROR;
}

extern void init_scores(t_app *app)
{
	for (int i = 0; i < 10; i++) {
		app->scores[i].score = DEFAULT_SCORE;
		snprintf(
			app->scores[i].name,
			sizeof(app->scores[i].name),
			"%s", DEFAULT_NAME
		);
	}
}

static bool is_valid_score_name(const char *name)
{
	for (int i = 0; name[i] != '\0'; i++) {
		if (name[i] < 'A' || name[i] > 'Z')
			return false;
	}
	return true;
}

extern t_errcode parse_scores(t_app *app)
{
	FILE *file = fopen(SCORE_FILE_NAME, "r");
	if (file == NULL) {
		if (errno != ENOENT)
			return FILE_ERROR;
		file = fopen(SCORE_FILE_NAME, "w");
		if (file == NULL)
			return FILE_ERROR;
		if (fclose(file) == EOF)
			return FILE_ERROR;
		return NO_ERROR;
	}

	char line[256];
	for (int i = 0; i < 10 && fgets(line, sizeof(line), file) != NULL; i++) {
		if (sscanf(
				line, "%10s %ld", app->scores[i].name, &app->scores[i].score
			) != 2) {
			if (fclose(file) == EOF)
				return FILE_ERROR | PARSE_ERROR;
			return PARSE_ERROR;
		}

		if (!is_valid_score_name(app->scores[i].name)) {
			if (fclose(file) == EOF)
				return FILE_ERROR | PARSE_NAME_ERROR;
			return PARSE_NAME_ERROR;
		}
	}

	if (fclose(file) == EOF)
		return FILE_ERROR;
	return NO_ERROR;
}
