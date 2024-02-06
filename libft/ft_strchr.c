/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:17 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/01 12:45:18 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *src, char c)
{
	char	*ptr;

	ptr = (char *)src;
	while (*(ptr) != c)
	{
		if (*ptr == 0)
			return (0);
		ptr++;
	}
	return (ptr);
}
