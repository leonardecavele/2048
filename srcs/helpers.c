/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:02:20 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 17:39:27 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

extern int64_t	max(int64_t a, int64_t b)
{
	return a > b ? a : b;
}

extern int64_t	min(int64_t a, int64_t b)
{
	return a < b ? a : b;
}

extern int nbrlen(int64_t nbr)
{
	int	len = 0;

	if (nbr == 0)
		return (1);

	while (nbr > 0) {
		nbr /= 10;
		len++;
	}
	return (len);
}
