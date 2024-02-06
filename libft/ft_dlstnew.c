/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:05:09 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 17:18:00 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*result;

	result = (t_dlist *)malloc(sizeof(t_dlist));
	if (result == 0)
		return (0);
	result->content = content;
	result->next = 0;
	result->prev = 0;
	result->median = 0;
	result->next_lowest = 0;
	result->next_highest = 0;
	return (result);
}
