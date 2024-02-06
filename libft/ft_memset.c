/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:58:49 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:37:03 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t size)
{
	char	*p;

	p = s;
	while (size--)
		*p++ = (unsigned char) c;
	return (s);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    char str1[20];

    // Fill str with 'A' for the first 10 characters
    memset(str1, 'A', 10);

    // Null-terminate the string manually
    // since memset doesn't add a null terminator
    str1[10] = '\0';

    // Print the result
    printf("   memset: %s\n", str1);

	char str2[20];
	ft_memset(str2, 'B', 1);
	str2[1] = '\0';
    	printf("ft_memset: %s\n", str2);

    return 0;
}
*/
