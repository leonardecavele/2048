/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:24:11 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/07 12:55:22 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (i + 1 < n && ((uint8_t *)s1)[i] == ((uint8_t *)s2)[i])
		i++;
	return (((uint8_t *)s1)[i] - ((uint8_t *)s2)[i]);
}
