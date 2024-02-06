/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:03:33 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:35:38 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*ptr;

	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substring = (char *)malloc(len + 1);
	if (substring == 0)
		return (0);
	ptr = substring;
	while (len--)
		*(ptr++) = *((s++) + start);
	*ptr = '\0';
	return (substring);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{

	char s[] = "long-word";
	printf("%s\n", ft_substr(s, ft_strlen(s), ft_strlen(s)));	
	return (0);
}
*/
