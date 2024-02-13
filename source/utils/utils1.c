/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:50:52 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/13 15:02:16 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	free_strarr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i] != NULL)
		free(strarr[i++]);
	free(strarr);
}

int	fdf_row_num(char *fdf_file)
{
	int		fdf_fd;
	char	*line;
	int		horizontal_positions;

	horizontal_positions = 0;
	fdf_fd = open(fdf_file, O_RDONLY);
	if (fdf_fd < 0)
		return (0);
	line = get_next_line(fdf_fd, RESET_BUFFER);
	while (line != NULL)
	{
		horizontal_positions++;
		free(line);
		line = get_next_line(fdf_fd, DEFAULT);
	}
	close(fdf_fd);
	return (horizontal_positions);
}

int	fdf_column_num(char *fdf_file)
{
	int		fdf_fd;
	char	*first_line;
	char	**first_line_split;
	int		vertical_positions;

	vertical_positions = 0;
	fdf_fd = open(fdf_file, O_RDONLY);
	if (fdf_fd < 0)
		return (0);
	first_line = get_next_line(fdf_fd, RESET_BUFFER);
	if (first_line)
	{
		first_line_split = ft_split(first_line, ' ');
		if (first_line_split != NULL)
		{
			while (first_line_split[vertical_positions]
				&& *first_line_split[vertical_positions] != '\n')
				vertical_positions++;
			free_strarr(first_line_split);
		}
	}
	free(first_line);
	close(fdf_fd);
	return (vertical_positions);
}

int	is_integer(char *str)
{
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_hexadecimal(char *str)
{
	while (*str && ft_isdigit(*str))
		str++;
	if (*str != ',')
		return (0);
	if (ft_strncmp(",0x", str, 3) != 0)
		return (0);
	str += 3;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) && ft_tolower(*str) < 'a'
			&& ft_tolower(*str) > 'F')
			return (0);
		str++;
	}
	return (1);
}
