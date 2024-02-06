/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:20:48 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 17:18:15 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	**ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*current_node;

	if (lst == 0 || new == 0)
		return (0);
	if (*lst == 0)
		*lst = new;
	else
	{
		current_node = *lst;
		while (current_node->next != 0)
			current_node = current_node->next;
		current_node->next = new;
		new->prev = current_node;
		new->next = NULL;
	}
	return (lst);
}

/*
#include <stdio.h>
#include <string.h>

void	print_result(t_dlist *lst, t_dlist *expected_result)
{
	int	i;
	int	passed;

	i = 0;
	passed = 1;
	while (expected_result != 0)
	{
		printf("List element: (%d)\n", i++);
		printf("Expected value:\t'%s'\n", (char *)expected_result->content);
		printf("Actual value:\t'%s'\n", (char *)lst->content);
		if (strcmp(expected_result->content, lst->content) != 0)
			passed = 0;
		expected_result = (expected_result)->next;
		lst = (lst)->next;
	}
	printf("Passed:\t%s\n", passed ? "Yes" : "No");
	printf("\n");
}
int	main(void)
{
   // void    ft_dlstadd_back(t_dlist **lst, t_dlist *new)
   printf("Test Case 1: Testing adding element to the back of empty list.\n");
	t_dlist   *element_1_1 = ft_dlstnew(ft_strdup("1"));

	t_dlist   *expected_result_1 = element_1_1;

	t_dlist   *begin_1 = 0;
	ft_dlstadd_back(&begin_1, ft_dlstnew(ft_strdup("1")));

	print_result(begin_1, expected_result_1);

	printf("Test Case 2: Testing adding element to the back of existing list."
			"\n");
	t_dlist  *element_1_2 = ft_dlstnew(ft_strdup("1"));
	t_dlist  *element_2_2 = ft_dlstnew(ft_strdup("2"));
	t_dlist  *element_3_2 = ft_dlstnew(ft_strdup("3"));

	t_dlist   *expected_result_2 = element_1_2;
	expected_result_2->next = element_2_2;
	expected_result_2->next->next = element_3_2;

	t_dlist  *begin_2 = 0;
	ft_dlstadd_back(&begin_2, ft_dlstnew(ft_strdup("1")));
	ft_dlstadd_back(&begin_2, ft_dlstnew(ft_strdup("2")));
	ft_dlstadd_back(&begin_2, ft_dlstnew(ft_strdup("3")));

	print_result(begin_2, expected_result_2);
}*/
