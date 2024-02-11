/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:26:37 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/10 21:07:18 by vketteni         ###   ########.fr       */
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
	double min_x;
	double min_y;
	double max_x;
	double max_y;

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