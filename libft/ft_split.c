/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:15:25 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:36:40 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <stddef.h>

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	if (!s)
		return (0);
	result = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			result[i++] = ft_substr(s, 0, len);
			s += len;
		}
		else
			s++;
	}
	return (result);
}
/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to free the memory allocated for the result of ft_split
void	free_split_result(char **result)
{
	int i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int main(void)
{
	// Test Case 1: Testing split on an empty string
	printf("Test Case 1: Testing split on an empty string.\n");
	char *test_1 = "";
	char **result_1 = ft_split(test_1, ' ');
	char *expected_1[] = {"" ,NULL};
	printf("String:\t\t'%s'\n", test_1);
	printf("Delimiter:\t'%s'\n", " ");
	printf("Result:\t\t'%s'\n", result_1[0]);
	printf("Expected:\t'%s'\nPass:\t\t%s\n\n", expected_1[0],
			  *result_1[0] == *expected_1[0]
			  && result_1[1] == expected_1[1] ? "Yes" : "No");
	free_split_result(result_1);

	// Test Case 2: Testing split with a char that isn't in string
	printf("Test Case 2: Testing split with a char that isn't in string.\n");
	char *test_2 = "ThisIsAString";
	char **result_2 = ft_split(test_2, ' ');
	char *expected_2[] = {"ThisIsAString", NULL};
	printf("String:\t\t'%s'\n", test_2);
	printf("Delimiter:\t'%s'\n", " ");
	printf("Result:\t\t'%s'\n",result_2[0]);
	printf("Expected:\t'%s'\n", expected_2[0]);
	printf("Pass:\t\t%s\n\n",
		   strcmp(result_2[0], expected_2[0]) == 0
		   && result_2[1] == expected_2[1] ? "Yes" : "No");
	free_split_result(result_2);

	// Test Case 3: Testing split with a char that is in string
	printf("Test Case 3: Testing split with a char that is in string.\n");
	char *test_3 = "Split,This,String";
	char **result_3 = ft_split(test_3, ',');
	char *expected_3[] = {"Split", "This", "String", NULL};
	printf("String:\t\t'%s'\n", test_3);
	printf("Delimiter:\t'%s'\n", ",");
	printf("Result:\t\t'%s' '%s' '%s'\n",
		   result_3[0], result_3[1], result_3[2]);
	printf("Expected:\t'%s' '%s' '%s'\n",
		   expected_3[0], expected_3[1], expected_3[2]);
	printf("Pass:\t\t%s\n\n",
		   strcmp(result_3[0], expected_3[0]) == 0
		   && strcmp(result_3[1], expected_3[1]) == 0
		   && strcmp(result_3[2], expected_3[2]) == 0
		   && result_3[3] == expected_3[3] ? "Yes" : "No");
	free_split_result(result_3);

	// Test Case 4: Testing split with a match on the first char in string
	printf("Test Case 4: Testing split with a match "
		   "on the first char in string.\n");
	char *test_4 = "FirstMatchInTheString";
	char **result_4 = ft_split(test_4, 'F');
	char *expected_4[] = {"irstMatchInTheString", NULL};
	printf("String:\t\t'%s'\n", test_4);
		printf("Delimiter:\t'%s'\n", "F");
		printf("Result:\t\t'%s'\n",result_4[0]);
		printf("Expected:\t'%s'\n", expected_4[0]);
		printf("Pass:\t\t%s\n\n", strcmp(result_4[0], expected_4[0]) == 0
		   && strcmp(result_4[1], expected_4[1]) == 0 ? "Yes" : "No");
	free_split_result(result_4);

	// Test Case 5: Testing split with a match on the final char in string
	printf("Test Case 5: Testing split with a match "
		   "on the final char in string.\n");
	char *test_5 = "StringWithMatchZ";
	char **result_5 = ft_split(test_5, 'Z');
	char *expected_5[] = {"StringWithMatch", NULL};
	printf("String:\t\t'%s'\n", test_5);
	printf("Delimiter:\t'%s'\n", "Z");
	printf("Result:\t\t'%s'\n", result_5[0]);
	printf("Expected:\t'%s'\n", expected_5[0]);
	printf("Pass:\t\t%s\n\n",
		   strcmp(result_5[0], expected_5[0]) == 0  ? "Yes" : "No");
	free_split_result(result_5);

	//Test Case 6: Testing split with a match on two successive chars in string
	printf("Test Case 6: Testing split with a match "
		   "on two successive chars in string.\n");
	char *test_6 = "SuccessiveMatch";
	char **result_6 = ft_split(test_6, 's');
	char *expected_6[] = {"Succe","iveMatch", NULL};
	printf("String:\t\t'%s'\n", test_6);
	printf("Delimiter:\t'%s'\n", "s");
	printf("Result:\t\t'%s' '%s'\n", result_6[0], result_6[1]);
	printf("Expected:\t'%s' '%s'\n", expected_6[0], expected_6[1]);
	printf("Pass:\t\t%s\n\n", strcmp(result_6[0], expected_6[0]) == 0
		   && strcmp(result_6[1], expected_6[1]) == 0
		   && strcmp(result_6[2], expected_6[2]) == 0 ? "Yes" : "No");
	free_split_result(result_6);

	// Test Case 7: Testing split with match on every char in string.
	printf("Test Case 7: Testing split with match "
		   "on every char in string.");
	char *test_7 = "AAAAAAAAA";
	char **result_7 = ft_split(test_7, 'A');
	char *expected_7[] = {NULL};
	printf("String:\t\t'%s'\n", test_7);
	printf("Delimiter:\t'%s'\n", "A");
	printf("Result:\t\t'%p'\n", result_7[0]);
	printf("Expected:\t'%p'\n", expected_7[0]);
	printf("Pass:\t\t%s\n\n",
		   *result_7[0] == *expected_7[0] ? "Yes" : "No");

	return 0;
}
*/