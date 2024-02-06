/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:17 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:36:04 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	char	*start;

	start = (char *)str;
	while (*(str))
		str++;
	return (str - start);
}

/*
#include <stdio.h>
#include <string.h>
int main (void)
{
        char* c;
        c = "";
        printf("%ld\n", ft_strlen(c));
        printf("%ld\n", strlen(c));
}
*/
