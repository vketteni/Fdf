/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:48:33 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:38:08 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*result_ptr;

	total_size = nmemb * size;
	if (total_size > SIZE_MAX)
		return (0);
	result_ptr = malloc(total_size);
	if (!result_ptr)
		return (0);
	result_ptr = ft_memset(result_ptr, 0, total_size);
	return (result_ptr);
}
