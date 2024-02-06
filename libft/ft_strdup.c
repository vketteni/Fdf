/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:18:16 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:36:29 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*string_duplicate;
	size_t	arr_size;

	arr_size = ft_strlen((char *)s) + 1;
	string_duplicate = (char *)malloc(arr_size);
	if (string_duplicate == 0)
		return (0);
	ft_strlcpy(string_duplicate, (char *)s, arr_size);
	return (string_duplicate);
}
