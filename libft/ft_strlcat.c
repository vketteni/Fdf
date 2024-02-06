/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:25:20 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/15 09:36:11 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	space_left;
	size_t	chars_to_copy;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_size <= dst_len)
		return (dst_size + src_len);
	space_left = dst_size - dst_len - 1;
	chars_to_copy = src_len;
	if (src_len >= space_left)
		chars_to_copy = space_left;
	ft_strlcpy(dst + dst_len, src, chars_to_copy + 1);
	dst[dst_len + chars_to_copy] = 0;
	return (dst_len + src_len);
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	char	*dst;
	size_t	buffer_size = 15;

	if (!(dst = (char *) malloc(sizeof(char) * buffer_size)))
		return (0);
	ft_memset(dst, 0, buffer_size);
	ft_memset(dst, 'r', 6);
// Testing the function when there is enough space in the destination buffer
// to ccat the source string.
	if (111)
	{
		dst[11] = 'a';
		printf("%ld\n", ft_strlcat(dst, "lorem", buffer_size));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
// Test when the source string is an empty string.
	if (111)
	{
		printf("%ld\n", ft_strlcat(dst, "", buffer_size));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
// Test when the destination buffer is initially an empty string.
	if (111)
	{
		ft_memset(dst, 0, 6);
		printf("%ld\n", ft_strlcat(dst, "lorem", buffer_size));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
// Test when there is not enough space in the destination buffer to fully
// concatenate the source string.
	if (111)
	{
		printf("%ld\n", ft_strlcat(dst, "lorem ipsum dolor sit amet",
								   buffer_size));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
// Test with a destination size of 0, which should not modify the destination.
	if (111)
	{
		printf("%ld\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 0));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
// Test with a destination size of 1, which should have limited space for
// concatenation.
	if (111)
	{
		printf("%ld\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 1));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
// Testing when the destination buffer size is smaller than the source string
// length.
	if (111)
	{
		printf("%ld\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 5));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
// Testing when the destination buffer size is exactly equal to the source
// string length.
	if (111)
	{
		printf("%ld\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 6));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
// Testing when the destination buffer is almost full, leaving space for the
// null terminator.
	if (111)
	{
		ft_memset(dst, 'r', 14);
		printf("%ld\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 15));
		write(1, dst, buffer_size);
		write(1, "\n", 1);
	}
	return (0);
}
*/
