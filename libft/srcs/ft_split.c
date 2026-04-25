/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:11:04 by ldecavel          #+#    #+#             */
/*   Updated: 2026/01/24 17:01:05 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_strips(size_t strips, char **split)
{
	while (split[++strips])
		free(split[strips]);
	free(split);
	return (NULL);
}

static size_t	count_strips(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	strips;
	char	**split;
	size_t	i;
	size_t	temp;

	if (!s)
		return (NULL);
	strips = count_strips(s, c);
	split = ft_calloc(strips--, sizeof(char *));
	if (!split)
		return (NULL);
	i = ft_strlen(s);
	while (strips > 0)
	{
		while (i > 0 && s[i - 1] == c)
			i--;
		temp = i;
		while (i > 0 && s[i - 1] != c)
			i--;
		split[--strips] = ft_substr(s, i, temp - i);
		if (!split[strips])
			return (free_strips(strips, split));
	}
	return (split);
}
