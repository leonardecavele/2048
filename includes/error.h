/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:23:36 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 12:46:41 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* use this when returning error codes */
typedef int	t_errcode;

/* add error codes here */
/* used bitwise */
typedef enum e_errcodes
{
	NO_ERROR = 0,
	ARG_COUNT_ERROR = (1 << 0),
	INVALID_ARG_ERROR = (1 << 1),
	NCURSES_ERROR = (1 << 2),
	SIGNAL_ERROR = (1 << 3)
}	t_errcodes;

t_errcode	errcode_message(t_errcode errcode);

#endif
