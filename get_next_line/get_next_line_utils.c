/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:05:52 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/06 02:00:18 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *old_memory, size_t new_size)
{
	char	*new_memory;
	size_t	i;

	new_memory = (char *)malloc(sizeof(char) * new_size);
	if (new_memory == 0)
		return (0);
	i = 0;
	if (old_memory)
	{
		while (old_memory[i] != '\0')
		{
			new_memory[i] = old_memory[i];
			i++;
		}
		free(old_memory);
	}
	while (i < new_size)
		new_memory[i++] = '\0';
	return (new_memory);
}

int	ft_strlen(char *str)
{
	char	*start;

	start = (char *)str;
	while (*(str))
		str++;
	return (str - start);
}

int	ft_write_buffer_to_line(char *buffer, char *line, int buff_pos, int new_end)
{
	int	start;
	int	line_length;

	start = buff_pos;
	line_length = ft_strlen(line);
	while (buff_pos < new_end)
		line[line_length++] = buffer[buff_pos++];
	if (buffer[buff_pos] != '\0')
		line[line_length++] = buffer[buff_pos];
	line[line_length] = '\0';
	return (buff_pos - start);
}

char	*ft_process_buffer_into_line(char *buffer, int *buff_pos, char *line,
		int bytes_read)
{
	int	line_length;
	int	new_end;

	new_end = *buff_pos;
	line_length = 0;
	if (line)
		line_length = ft_strlen(line);
	while (new_end < BUFFER_SIZE - 1 && new_end < bytes_read - 1
		&& buffer[new_end] != '\0' && (buffer[new_end] != '\n'))
		new_end++;
	if (buffer[new_end] == '\0')
		line = ft_realloc(line, line_length + (new_end - *buff_pos) + 1);
	else
		line = ft_realloc(line, line_length + (new_end - *buff_pos) + 2);
	if (line == NULL)
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	*buff_pos += ft_write_buffer_to_line(buffer, line, *buff_pos, new_end);
	return (line);
}
