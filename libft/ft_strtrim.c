/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:15:49 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:35:43 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_string;
	size_t	arr_size;
	char	*start;
	char	*end;

	while (*s1 && ft_char_in_set(*s1, set))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = (char *)s1;
	while (*s1)
		s1++;
	while (*(s1 - 1) && ft_char_in_set(*(s1 - 1), set))
		s1--;
	end = (char *)s1;
	arr_size = end - start + 1;
	trimmed_string = (char *)malloc(arr_size);
	if (!trimmed_string)
		return (0);
	s1 = start;
	while (s1 < end)
		*trimmed_string++ = *s1++;
	*trimmed_string = '\0';
	return (trimmed_string - (end - start));
}

/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int	main(void)
{
	// Test Case 1: Testing trim from both sides
	const char *s1_1 = "   Hello, World!   ";
	const char *set_1 = " ";
	const char *expected_1 = "Hello, World!";
	char *result_1 = ft_strtrim(s1_1, set_1);
	printf("Test Case 1: Testing trim from both sides.\n");
	printf("Result:\t\t'%s'\nExpected:\t'%s'\nPass:\t\t%s\n\n",
		   result_1, expected_1, strcmp(result_1, expected_1) == 0 ? "Yes" : "No");

	// Test Case 2: Testing trim from front
	const char *s1_2 = "   Hello, World!";
	const char *set_2 = " ";
	const char *expected_2 = "Hello, World!";
	char *result_2 = ft_strtrim(s1_2, set_2);
	printf("Test Case 2: Testing trim from front.\n");
	printf("Result:\t\t'%s'\nExpected:\t'%s'\nPass:\t\t%s\n\n",
		   result_2, expected_2, strcmp(result_2, expected_2) == 0 ? "Yes" : "No");

	// Test Case 3: Testing trim from back
	const char *s1_3 = "Hello, World!   ";
	const char *set_3 = " ";
	const char *expected_3 = "Hello, World!";
	char *result_3 = ft_strtrim(s1_3, set_3);
	printf("Test Case 3: Testing trim from back.\n");
	printf("Result:\t\t'%s'\nExpected:\t'%s'\nPass:\t\t%s\n\n",
		   result_3, expected_3, strcmp(result_3, expected_3) == 0 ? "Yes" : "No");

	// Test Case 4: Testing trim of empty string
	const char *s1_4 = "";
	const char *set_4 = " ";
	const char *expected_4 = "";
	char *result_4 = ft_strtrim(s1_4, set_4);
	printf("Test Case 4: Testing trim of empty string.\n");
	printf("Result:\t\t'%s'\nExpected:\t'%s'\nPass:\t\t%s\n\n",
		   result_4, expected_4, strcmp(result_4, expected_4) == 0 ? "Yes" : "No");

	// Test Case 5: Testing trim with empty set
	const char *s1_5 = "Hello, World!";
	const char *set_5 = "";
	const char *expected_5 = "Hello, World!";
	char *result_5 = ft_strtrim(s1_5, set_5);
	printf("Test Case 5: Testing trim with empty set.\n");
	printf("Result:\t\t'%s'\nExpected:\t'%s'\nPass:\t\t%s\n\n",
		   result_5, expected_5, strcmp(result_5, expected_5) == 0 ? "Yes" : "No");

	// Test Case 6: Testing trim with no match in set
	const char *s1_6 = "Hello, World!";
	const char *set_6 = "-";
	const char *expected_6 = "Hello, World!";
	char *result_6 = ft_strtrim(s1_6, set_6);
	printf("Test Case 6: Testing trim with no match in set.\n");
	printf("Result:\t\t'%s'\nExpected:\t'%s'\nPass:\t\t%s\n\n",
		   result_6, expected_6, strcmp(result_6, expected_6) == 0 ? "Yes" : "No");

	// Test Case 7: Testing trim with match on every char in string.
	const char	*s1_7 = "XXAAXXAA";
	const char	*set_7 = "AX";
	const char *expected_7 = "";
	char *result_7 = ft_strtrim(s1_7, set_7);
	printf("Test Case 7: Testing trim with match on every char in string.\n");
	printf("Result:\t\t'%s'\n", result_7);
	printf("Expected:\t'%s'\n", expected_7);
	printf("Passed:\t\t'%s'\n", strcmp("", result_7) == 0 ? "Yes" : "No");

	return 0;
}*/