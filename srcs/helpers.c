/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:02:20 by ldecavel          #+#    #+#             */
/*   Updated: 2026/04/25 17:24:06 by ldecavel         ###   ########.fr       */
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
