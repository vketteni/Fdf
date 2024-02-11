/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:41:54 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/09 14:16:17 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_fdf_checker	*initialize_fdf_checker(void)
{
	t_fdf_checker	*checker;

	checker = (t_fdf_checker *)malloc(sizeof(t_fdf_checker));
	if (!checker)
		return (NULL);
	checker->fdf_fd = -1;
	checker->elem_per_line = -1;
	checker->line = NULL;
	checker->line_elements = NULL;
	return (checker);
}

static void	terminate_checker(t_fdf_checker *checker)
{
	if (checker->line)
		free(checker->line);
	if (*(checker->line_elements))
		free_strarr(checker->line_elements);
	close(checker->fdf_fd);
	free(checker);
}

static int	fdf_check_line(t_fdf_checker *checker)
{
	int		i;
	char	*line_elem;

	if (!checker || !checker->elem_per_line)
		return (-1);
	i = 0;
	line_elem = (checker->line_elements)[i];
	while (line_elem && *line_elem != '\n')
	{
		if (!is_number(line_elem))
			return (-1);
		line_elem = (checker->line_elements)[++i];
	}
	if (line_elem == NULL)
		return (-1);
	if (checker->elem_per_line == -1)
		checker->elem_per_line = i;
	else if (checker->elem_per_line != i)
		return (-1);
	return (0);
}

int	fdf_checker(char *fdf_file)
{
	t_fdf_checker	*checker;

	checker = initialize_fdf_checker();
	if (!checker)
		return (-1);
	checker->fdf_fd = open(fdf_file, O_RDONLY);
	if (checker->fdf_fd < 0)
		return (-1);
	checker->line = get_next_line(checker->fdf_fd, RESET_BUFFER);
	while (checker->line != NULL)
	{
		checker->line_elements = ft_split(checker->line, ' ');
		if (!checker->line_elements || fdf_check_line(checker) == -1)
		{
			terminate_checker(checker);
			return (-1);
		}
		free_strarr(checker->line_elements);
		free(checker->line);
		checker->line = get_next_line(checker->fdf_fd, DEFAULT);
	}
	terminate_checker(checker);
	return (0);
}
