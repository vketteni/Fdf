/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:32:36 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/08 23:27:29 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#  define RESET_BUFFER 1
#  define DEFAULT 0
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd, int reset);
char	*ft_realloc(char *str, size_t new_size);
char	*ft_process_buffer_into_line(char *buffer, int *buff_pos, char *line,
			int bytes_read);

#endif