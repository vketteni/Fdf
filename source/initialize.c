/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:31:49 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/11 20:50:04 by vketteni         ###   ########.fr       */
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

int	initialize_min_max(t_param *param)
{
	if (!param)
		return (-1);
	param->min_coord = min_coord(param->all_coordinates);
	param->max_coord = max_coord(param->all_coordinates);
	if (!param->min_coord || !param->max_coord)
		return (-1);
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
		param->angle = 0;
	}
}

int	initialize_param(char *fdf_file, t_param *param)
{
	set_null(param);
	param->angle = 30;
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
	if (isometric(param->all_coordinates, param) == -1)
		return (-1);
	if (initialize_min_max(param) == -1)
		return (-1);
	if (normalize_scale_center(param->all_coordinates, param) == -1)
		return (-1);
	return (0);
}
