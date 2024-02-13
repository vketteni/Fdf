/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:37:43 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/13 19:59:44 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	normalize_scale_center(t_coordinate ***all_coordinates, t_param *param)
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
			if (normalize(all_coordinates[i][j], param) == -1
				|| scale(all_coordinates[i][j], param) == -1
				|| center(all_coordinates[i][j], param) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

t_coordinate	*create_coordinate(int x, int y, int z)
{
	t_coordinate	*coordinate;

	coordinate = (t_coordinate *)malloc(sizeof(t_coordinate));
	if (!coordinate)
		return (NULL);
	coordinate->x = x;
	coordinate->y = y;
	coordinate->z = z;
	return (coordinate);
}
