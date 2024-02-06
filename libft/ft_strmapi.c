/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:16 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:36:00 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (*(s + i))
	{
		*(result + i) = f(i, *(s + i));
		i++;
	}
	*(result + i) = '\0';
	return (result);
}
