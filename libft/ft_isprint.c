/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:20:04 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/01 13:18:17 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(unsigned int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int main (void)
{
	unsigned char c;
	c = 128;
	printf("%d\n", ft_isprint(c));
	printf("%d\n", isprint(c));
}
*/
