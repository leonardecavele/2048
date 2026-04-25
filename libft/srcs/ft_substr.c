/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:00:48 by ldecavel          #+#    #+#             */
/*   Updated: 2026/01/24 17:01:27 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*ptr;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if ((size_t)start >= str_len)
		return (ft_strdup(""));
	str_len -= (size_t)start;
	if (str_len > len)
		str_len = len;
	ptr = malloc(str_len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, &s[start], str_len);
	ptr[str_len] = 0;
	return (ptr);
}
