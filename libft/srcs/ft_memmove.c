/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:34:31 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/07 12:55:22 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	l_memcpy(void *dst, const void *src, size_t n)
{
	while (n--)
		((uint8_t *)dst)[n] = ((uint8_t *)src)[n];
}

static void	r_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i];
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst < src)
		r_memcpy(dst, src, n);
	else
		l_memcpy(dst, src, n);
	return (dst);
}
