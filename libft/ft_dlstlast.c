/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:24:24 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 17:17:34 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*current_node;

	if (lst == 0)
		return (0);
	current_node = lst;
	while (current_node->next != 0)
		current_node = current_node->next;
	return (current_node);
}
