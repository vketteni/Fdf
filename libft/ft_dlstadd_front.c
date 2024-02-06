/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:23:09 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 17:18:32 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	**ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*current_head;

	if (lst == 0 || new == 0)
		return (0);
	if (*lst == 0)
		*lst = new;
	else
	{
		current_head = *lst;
		while (current_head->prev != NULL)
			current_head = current_head->prev;
		current_head->prev = new;
		new->next = current_head;
		new->prev = NULL;
		*lst = new;
	}
	return (lst);
}
