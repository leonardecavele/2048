/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:35:00 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 12:37:23 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* extern */
#include <signal.h>
#include <stdbool.h>

/* intern */
#include "error.h"
#include "signals.h"

static volatile sig_atomic_t g_signals = 0;

static void	winch_signal(int sig)
{
	(void)sig;
	g_signals |= SIGNAL_RESIZE;
}

static void	exit_signal(int sig)
{
	(void)sig;
	g_signals |= SIGNAL_EXIT;
}

extern t_errcode signals_init(void)
{
	t_errcode	errcode;

	errcode = NO_ERROR;
	if (signal(SIGWINCH, winch_signal) == SIG_ERR
		|| signal(SIGINT, exit_signal) == SIG_ERR
		|| signal(SIGTERM, exit_signal) == SIG_ERR
		|| signal(SIGQUIT, exit_signal) == SIG_ERR)
		errcode |= SIGNAL_ERROR;
	return (errcode);
}

extern bool must_exit(void)
{
	return ((g_signals & SIGNAL_EXIT) != 0);
}

extern bool must_resize(void)
{
	if ((g_signals & SIGNAL_RESIZE) == 0)
		return (false);
	g_signals &= ~SIGNAL_RESIZE;
	return (true);
}
