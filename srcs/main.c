/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 01:51:37 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 02:25:48 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	/* use OR to update it with functions
	   errcode |= func();
	*/
	t_errcode errcode = NO_ERROR;

	return errcode_message(errcode);
}
