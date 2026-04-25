/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:58:01 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 12:36:56 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
#define SIGNALS_H

#include <signal.h>
#include <stdbool.h>

typedef enum e_signals {
	SIGNAL_RESIZE = (1 << 0),
	SIGNAL_EXIT = (1 << 1)
}	t_signals;

t_errcode signals_init(void);
bool must_exit(void);
bool must_resize(void);

#endif
