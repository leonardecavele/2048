/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:55:32 by ldecavel          #+#    #+#             */
/*   Updated: 2026/01/24 17:01:24 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const c, char const *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && is_charset(*s1, set))
		s1++;
	len = 0;
	while (s1[len])
		len++;
	while (len > 0 && is_charset(s1[len - 1], set))
		len--;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	ptr[len] = 0;
	return (ptr);
}
