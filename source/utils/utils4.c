/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:45:20 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/14 12:41:15 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	max_coord(t_coordinate *coord ,t_param *param)
{
	if (!coord || !param || !param->max_coord)
		return (-1);
	param->max_coord->x = fmax(coord->x, param->max_coord->x);
	param->max_coord->y = fmax(coord->y, param->max_coord->y);
	param->max_coord->z = fmax(coord->z, param->max_coord->z);
	return (0);
}

int	min_coord(t_coordinate *coord ,t_param *param)
{
	if (!coord || !param || !param->min_coord)
		return (-1);
	param->min_coord->x = fmin(coord->x, param->min_coord->x);
	param->min_coord->y = fmin(coord->y, param->min_coord->y);
	param->min_coord->z = fmin(coord->z, param->min_coord->z);
	return (0);
}

void	set_null(t_param *param)
{
	if (param)
	{
		param->mlx = NULL;
		param->image = NULL;
		param->all_coordinates = NULL;
		param->max_coord = NULL;
		param->min_coord = NULL;
		param->fdf_row_num = 0;
		param->fdf_column_num = 0;
		param->img_width_offset = 0;
		param->img_width = 0;
		param->img_height_offset = 0;
		param->img_height = 0;
	}
}
