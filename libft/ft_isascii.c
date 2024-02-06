/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:50:44 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/01 12:52:09 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
void main (void)
{
	unsigned int c;
	c = 0;
	printf("%c\n", c);
	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
}
*/
