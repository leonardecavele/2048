/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:16:32 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/07 13:13:39 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((uint8_t)(*s) == (uint8_t)c)
			return ((char *)s);
		s++;
	}
	if (!(uint8_t)c)
		return ((char *)s);
	return (0);
}
