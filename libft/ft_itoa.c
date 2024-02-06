/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:51:32 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:37:59 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_add_negative_sign(char *n_in_ascii, size_t len)
{
	size_t	last_index;

	last_index = len - 1;
	while (0 < last_index--)
		n_in_ascii[last_index + 1] = n_in_ascii[last_index];
	n_in_ascii[0] = '-';
	return (n_in_ascii);
}

static char	*ft_get_nbr_buffer(long n, int is_negative)
{
	char	*arr;
	size_t	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	if (is_negative)
		len++;
	arr = ft_calloc(len + 1, sizeof(char));
	if (!arr)
		return (0);
	arr[len] = '\0';
	return (arr);
}

static void	*ft_reverse(void *s, size_t len)
{
	size_t	i;
	size_t	j;
	char	tmp;
	char	*src;

	src = (char *)s;
	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = src[i];
		src[i++] = src[j];
		src[j--] = tmp;
	}
	return (src);
}

char	*ft_itoa_conversion(long n, int is_negative)
{
	char	*buffer;
	size_t	len;

	buffer = ft_get_nbr_buffer(n, is_negative);
	if (!buffer)
		return (0);
	len = 0;
	while (n > 0)
	{
		buffer[len++] = '0' + (n % 10);
		n /= 10;
	}
	ft_reverse(buffer, len);
	if (is_negative)
		ft_add_negative_sign(buffer, len + 1);
	return (buffer);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	long	nbr;

	nbr = (long)n;
	if (nbr == 0)
		return (ft_strdup("0"));
	is_negative = 0;
	if (nbr < 0)
	{
		is_negative = 1;
		nbr = -nbr;
	}
	result = ft_itoa_conversion(nbr, is_negative);
	if (!result)
		return (0);
	return (result);
}

/*#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main()
{
	char	*result;
	int n;
	char *expected;
	// gcc -g -o my_program
	// ft_itoa.c ft_calloc.c ft_strdup.c ft_memset.c ft_strlen.c ft_strlcpy.c
	// char	*ft_itoa(int n)
	n = -9;
	expected = "-9";
	printf("Test Case 1: Testing negative int (%d)\n", n);
	result = ft_itoa(n);
	printf("Expected:\t'%s'\nResult:\t\t'%s'\nPass:\t\t%s\n",
		   expected, result, strcmp(expected, result) == 0 ? "Yes" : "No");
	printf("\n\n");

	n = 9;
	expected = "9";
	printf("Test Case 2: Testing positive int (%d)\n", n);
	result = ft_itoa(n);
	printf("Expected:\t'%s'\nResult:\t\t'%s'\nPass:\t\t%s\n",
		   expected, result, strcmp(expected, result) == 0 ? "Yes" : "No");
	printf("\n");

	n = INT_MAX;
	expected = "2147483647";
	printf("Test Case 3: Testing int max (%d)\n", n);
	result = ft_itoa(n);
	printf("Expected:\t'%s'\nResult:\t\t'%s'\nPass:\t\t%s\n",
		   expected, result, strcmp(expected, result) == 0 ? "Yes" : "No");
	printf("\n");

	n = INT_MIN;
	expected = "-2147483648";
	printf("Test Case 4: Testing int min (%d)\n", n);
	result = ft_itoa(n);
	printf("Expected:\t'%s'\nResult:\t\t'%s'\nPass:\t\t%s\n",
		   expected, result, strcmp(expected, result) == 0 ? "Yes" : "No");
	printf("\n");

	n = 0;
	expected = "0";
	printf("Test Case 5: Testing zero (%d)\n", n);
	result = ft_itoa(n);
	printf("Expected:\t'%s'\nResult:\t\t'%s'\nPass:\t\t%s\n",
		   expected, result, strcmp(expected, result) == 0 ? "Yes" : "No");
	printf("\n");

	return (0);
}
*/