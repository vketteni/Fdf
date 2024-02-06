/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:31:44 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 17:17:45 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*result;
	t_dlist	*new;
	t_dlist	*tmp;

	result = (void *)0;
	while (lst != 0)
	{
		new = ft_dlstnew(f(lst->content));
		if (new == 0)
		{
			while (result != 0)
			{
				tmp = result;
				result = (result)->next;
				ft_dlstdelone(tmp, del);
			}
			return (0);
		}
		ft_dlstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
