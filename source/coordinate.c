/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:37:43 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/11 15:06:44 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

t_coordinate	*min_coord(t_coordinate ***all_coordinates)
{
	t_coordinate	*min;
	int				i;
	int				j;

	if (!all_coordinates)
		return (NULL);
	min = (t_coordinate *)malloc(sizeof(t_coordinate));
	if (!min)
		return (NULL);
	min->x = all_coordinates[0][0]->x;
	min->y = all_coordinates[0][0]->y;
	min->z = all_coordinates[0][0]->z;
	i = 0;
	while (all_coordinates[i])
	{
		j = 0;
		while (all_coordinates[i][j])
		{
			min->x = fmin(all_coordinates[i][j]->x, min->x);
			min->y = fmin(all_coordinates[i][j]->y, min->y);
			min->z = fmin(all_coordinates[i][j]->z, min->z);
			j++;
		}
		i++;
	}
	return (min);
}

t_coordinate	*max_coord(t_coordinate ***all_coordinates)
{
	t_coordinate	*max;
	int				i;
	int				j;

	if (!all_coordinates)
		return (NULL);
	max = (t_coordinate *)malloc(sizeof(t_coordinate));
	if (!max)
		return (NULL);
	max->x = all_coordinates[0][0]->x;
	max->y = all_coordinates[0][0]->y;
	max->z = all_coordinates[0][0]->z;
	i = 0;
	while (all_coordinates[i])
	{
		j = 0;
		while (all_coordinates[i][j])
		{
			max->x = fmax(all_coordinates[i][j]->x, max->x);
			max->y = fmax(all_coordinates[i][j]->y, max->y);
			max->z = fmax(all_coordinates[i][j]->z, max->z);
			j++;
		}
		i++;
	}
	return (max);
}

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
