/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:37 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/06 14:58:52 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = {0};
	static int	buff_pos = 0;
	static int	bytes_read = 0;
	char		*line;

	line = NULL;
	while (1)
	{
		if (buff_pos == 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (line && bytes_read == 0)
				return (line);
			if (bytes_read <= 0)
				return (NULL);
		}
		line = ft_process_buffer_into_line(buffer, &buff_pos, line, bytes_read);
		if (buffer[buff_pos] == '\n')
		{
			buff_pos = ((buff_pos + 1) % bytes_read);
			return (line);
		}
		if (buff_pos == BUFFER_SIZE - 1 || buff_pos == bytes_read - 1)
			buff_pos = 0;
	}
}
