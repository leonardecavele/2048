/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:15:14 by ldecavel          #+#    #+#             */
/*   Updated: 2025/08/30 16:47:04 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	void	*content;
	t_list	*res;

	if (!f || !del)
		return (NULL);
	start = 0;
	while (lst)
	{
		content = f(lst->content);
		res = ft_lstnew(content);
		if (!res)
		{
			del(content);
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, res);
		lst = lst->next;
	}
	return (start);
}
