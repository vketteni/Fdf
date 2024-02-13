/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:29:36 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/13 15:03:53 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_coordinate	*convert_to_isometric1(t_coordinate *coord)
{
	float	previous_x;
	float	previous_y;

	previous_x = coord->x;
	previous_y = coord->y;
	coord->x = (previous_x - previous_y) * cos(ANG_30);
	coord->y = (previous_x + previous_y) * sin(ANG_30) - coord->z;
	return (coord);
}

int	isometric(t_coordinate ***all_coordinates, t_param *param)
{
	int	i;
	int	j;

	if (!all_coordinates || !param)
		return (-1);
	i = 0;
	while (all_coordinates[i])
	{
		j = 0;
		while (all_coordinates[i][j])
		{
			all_coordinates[i][j]
				= convert_to_isometric1(all_coordinates[i][j]);
			if (!all_coordinates[i][j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
