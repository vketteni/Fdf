/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:31:49 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/09 00:11:45 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	initialize_coordinates(int	fdf_row_num, int fdf_column_num, t_param *param)
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

int	initialize_param(char *fdf_file, t_param *param)
{
	param->fdf_row_num = fdf_row_num(fdf_file);
	param->fdf_column_num = fdf_column_num(fdf_file);
	if (initialize_coordinates(param->fdf_row_num, param->fdf_column_num, param) == -1)
		return (-1);
	if (fdf_parse(fdf_file, param) == -1)
		return (-1);
	param->mlx = mlx_init(WIDTH, HEIGHT, "42Berlin", true);
	if (!(param->mlx))
	{
		puts(mlx_strerror(mlx_errno));
		terminate_param(param);
		return (EXIT_FAILURE);
	}
	return (0);
}
