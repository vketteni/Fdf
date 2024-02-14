/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:26:37 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/14 10:47:49 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	scale(t_coordinate *coord, t_param *param)
{
	if (!coord || !param)
		return (-1);
	coord->x *= (param->img_width / 2);
	coord->y *= (param->img_height / 2);
	return (0);
}

int	center(t_coordinate *coord, t_param *param)
{
	if (!coord || !param)
		return (-1);
	coord->x += param->img_width_offset;
	coord->y += param->img_height_offset;
	return (0);
}

int	normalize(t_coordinate *coord, t_param *param)
{
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;

	if (!coord || !param)
		return (-1);
	min_x = param->min_coord->x;
	min_y = param->min_coord->y;
	max_x = param->max_coord->x;
	max_y = param->max_coord->y;
	coord->x = (coord->x - min_x) / (max_x - min_x);
	coord->y = (coord->y - min_y) / (max_y - min_y);
	return (0);
}

int	adjust_extrem(t_param *param)
{
	t_coordinate	*max;

	if (!param)
		return (-1);
	max = create_coordinate(param->all_coordinates[0][0]->x,
			param->all_coordinates[0][0]->y,
			param->all_coordinates[0][0]->y);
		return (-1);
	if (coord_iter(param, max_coord) == -1)
	{
		free(max);
		return (-1);
	}
	if (max->z > 25)
	{
		if (coord_iter(param, adjust_z) == -1)
		{
			free(max);
			return (-1);
		}
	}
	free(max);
	return (0);
}

int	adjust_z(t_coordinate *coord, t_param *param)
{
	if (!coord || !param)
		return (-1);
	coord->z = coord->z / (param->fdf_row_num);
	return (0);
}
