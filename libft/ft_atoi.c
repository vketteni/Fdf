/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:36:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:38:37 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	is_negative;
	int	result;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (ft_strncmp((char *)nptr, "2147483648", 10) == 0)
		return (INT_MIN);
	is_negative = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_negative = 1;
		nptr++;
	}
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*(nptr++) - '0');
	}
	return (result * (1 + (is_negative * -2)));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
int main(void)
{
	char *nbr_buffer;
	size_t buffer_size = 15;

	if (!(nbr_buffer = (char *)malloc(sizeof(char) * buffer_size)))
		return (0);
	ft_memset(nbr_buffer, 0, buffer_size);

	// int	ft_atoi(const char *nptr)
	// Testing string with escape characters in front of the digits.
	if (true)
	{
		char whitespace[] = "\n\t\v\r\f 1";
		ft_strlcpy(nbr_buffer, whitespace, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = 1;
		printf("Testing string with escape characters in front of the digits."
			   "\n");
        printf("Result: %d, Expected: %d, Pass: %s\n\n"
			   , result, expected, result == expected ? "Yes" : "No");
	}

	// Testing negative number
	if (true)
	{
		char negative[] = "-42";
		ft_strlcpy(nbr_buffer, negative, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = -42;
		printf("Testing negative number\n");
		printf("Result: %d, Expected: %d, Pass: %s\n\n",
			   result, expected, result == expected ? "Yes" : "No");
	}

	// Testing positive number
	if (true)
	{
		char positive[] = "123";
		ft_strlcpy(nbr_buffer, positive, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = 123;
		printf("Testing positive number\n");
		printf("Result: %d, Expected: %d, Pass: %s\n\n",
			   result, expected, result == expected ? "Yes" : "No");
	}

	// Testing integer min
	if (true)
	{
		char int_min[] = "-2147483648";
		ft_strlcpy(nbr_buffer, int_min, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = -2147483648;
		printf("Testing integer min\n");
		printf("Result: %d, Expected: %d, Pass: %s\n\n",
			   result, expected, result == expected ? "Yes" : "No");
	}

	// Testing integer max
	if (true)
	{
		char int_max[] = "2147483647";
		ft_strlcpy(nbr_buffer, int_max, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = 2147483647;
		printf("Testing integer max\n");
		printf("Result: %d, Expected: %d, Pass: %s\n\n",
			   result, expected, result == expected ? "Yes" : "No");
	}

	// Testing bad char at the start
	if (true)
	{
		char bad_start[] = "abc123";
		ft_strlcpy(nbr_buffer, bad_start, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = 0;
		printf("Testing bad char at the start.\n");
		printf("Result: %d, Expected: %d, Pass: %s\n\n",
			   result, expected, result == expected ? "Yes" : "No");
	}

	// Testing bad char after whitespace
	if (true)
	{
		char bad_whitespace[] = "  a456";
		ft_strlcpy(nbr_buffer, bad_whitespace, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = 0;
		printf("Testing bad char after whitespace.\n");
		printf("Result: %d, Expected: %d, Pass: %s\n\n",
			   result, expected, result == expected ? "Yes" : "No");
	}

	// Testing bad char after sign
	if (true)
	{
		char bad_sign[] = "+a789";
		ft_strlcpy(nbr_buffer, bad_sign, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = 0;
		printf("Testing bad char after sign.\n");
		printf("Result: %d, Expected: %d, Pass: %s\n\n",
			   result, expected, result == expected ? "Yes" : "No");
	}

	// Testing bad char after number
	if (true)
	{
		char bad_after_number[] = "123x";
		ft_strlcpy(nbr_buffer, bad_after_number, buffer_size);
		int result = ft_atoi(nbr_buffer);
		int expected = 123; // Expected to stop conversion at 'x'.
        printf("Testing bad char after number.\n");
		printf("Result: %d, Expected: %d, Pass: %s\n\n",
			   result, expected, result == expected ? "Yes" : "No");
	}

	free(nbr_buffer);
	return (0);
}
*/