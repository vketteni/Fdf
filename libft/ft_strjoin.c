/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:13:13 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:36:21 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	size_t	arr_size;

	arr_size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	joined_string = malloc(arr_size);
	if (joined_string == 0)
		return (0);
	ft_strlcpy(joined_string, (char *)s1, arr_size);
	ft_strlcat(joined_string, (char *)s2, arr_size);
	return (joined_string);
}
