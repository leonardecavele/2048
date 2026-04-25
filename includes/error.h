/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:23:36 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 02:23:42 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* use this when returning error codes */
typedef int	t_errcode;

/* add error codes here */
/* used as bitwise offsets */
typedef enum e_errcodes
{
	NO_ERROR,
	MALLOC_ERROR,
	ARG_COUNT_ERROR,
	INVALID_ARG_ERROR
}	t_errcodes;

t_errcode	errcode_message(t_errcode errcode);

#endif
