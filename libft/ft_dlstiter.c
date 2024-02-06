/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:14:23 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 17:16:26 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(void *))
{
	t_dlist	*current_node;

	current_node = lst;
	while (current_node != 0)
	{
		f(current_node->content);
		current_node = current_node->next;
	}
}
