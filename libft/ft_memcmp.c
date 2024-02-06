/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:41:36 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:37:14 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = s1;
	str2 = s2;
	i = 0;
	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}

/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	s[] = {-128, 0, 127, 0};
	char	s_cpy[] = {-128, 0, 127, 0};
	char	s2[] = {0, 0, 127, 0};
	char	s3[] = {0, 0, 24, 0};

	printf("%d\n", ft_memcmp(s, s_cpy, 4));
	printf("%d\n", ft_memcmp(s, s2, 4));
	printf("%d\n", ft_memcmp(s2, s3, 4));
	return (0);
}
*/
