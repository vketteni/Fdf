/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:31:49 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/13 19:57:57 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	initialize_coordinates(int fdf_row_num, int fdf_column_num, t_param *param)
{
	int	row_index;

	if (!fdf_row_num || !fdf_column_num || !param)
		return (-1);
	param->all_coordinates = ft_calloc(fdf_row_num + 1,
			sizeof(t_coordinate **));
	if (param->all_coordinates == NULL)
		return (-1);
	row_index = 0;
	while (row_index < fdf_row_num)
	{
		param->all_coordinates[row_index] = calloc(fdf_column_num + 1,
				sizeof(t_coordinate *));
		if (param->all_coordinates[row_index] == NULL)
			return (-1);
		row_index++;
	}
	return (0);
}

int	initialize_image_boundaries(int fdf_row_num, int fdf_column_num,
		t_param *param)
{
	int	f;

	if (!fdf_row_num || !fdf_column_num)
		return (-1);
	f = 1;
	while (fdf_row_num > (WIDTH * f) / WINDOW_IMAGE_RATIO)
		f++;
	param->img_width = WIDTH * f;
	param->img_width_offset = param->img_width / 4;
	f = 1;
	while (fdf_column_num > (HEIGHT * f) / WINDOW_IMAGE_RATIO)
		f++;
	param->img_height = HEIGHT * f;
	param->img_height_offset = param->img_height / 4;
	return (0);
}

int	initialize_min(t_param *param)
{
	t_coordinate	*min;
	t_coordinate	*first;

	if (!param || param->all_coordinates)
		return (-1);
	first = param->all_coordinates[0][0];
	min = create_coordinate(first->x, first->y, first->z);
	if (!min)
		return (-1);
	param->min_coord = min;
	if (coord_iter(param, min_coord) == -1)
		return (-1);
	return (0);
}

int	initialize_max(t_param *param)
{
	t_coordinate	*max;
	t_coordinate	*first;

	if (!param || param->all_coordinates)
		return (-1);
	first = param->all_coordinates[0][0];
	max = create_coordinate(first->x, first->y, first->z);
	if (!max)
		return (-1);
	param->max_coord = max;
	if (coord_iter(param, max_coord) == -1)
		return (-1);
	return (0);
}

int	initialize_param(char *fdf_file, t_param *param)
{
	set_null(param);
	param->fdf_row_num = fdf_row_num(fdf_file);
	param->fdf_column_num = fdf_column_num(fdf_file);
	if (fdf_checker(fdf_file) == -1)
		return (-1);
	if (initialize_coordinates(param->fdf_row_num, param->fdf_column_num,
			param) == -1)
		return (-1);
	if (initialize_image_boundaries(param->fdf_row_num, param->fdf_column_num,
			param) == -1)
		return (-1);
	if (fdf_parse(fdf_file, param) == -1)
		return (-1);
	if (rotate_fdf_model(param) == -1)
		return (-1);
	if (isometric(param->all_coordinates, param) == -1)
		return (-1);
	if (initialize_min(param) == -1 || initialize_max(param) == -1)
		return (-1);
	if (normalize_scale_center(param->all_coordinates, param) == -1)
		return (-1);
	return (0);
}
