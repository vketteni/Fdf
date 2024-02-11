/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:29:36 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/11 15:03:01 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// static void	initialize_iso_transformation_matrix(float transformation_matrix[4][4])
// {
// 	transformation_matrix[0][0] = 1;
// 	transformation_matrix[0][1] = sqrt(2) / 2;
// 	transformation_matrix[0][2] = sqrt(2) / 2;
// 	transformation_matrix[0][3] = 1;
// 	transformation_matrix[1][0] = 0;
// 	transformation_matrix[1][1] = sqrt(2) / 2;
// 	transformation_matrix[1][2] = -sqrt(2) / 2;
// 	transformation_matrix[1][3] = 1;
// 	transformation_matrix[2][0] = -sqrt(2) / 3;
// 	transformation_matrix[2][1] = -sqrt(2) / 6;
// 	transformation_matrix[2][2] = -sqrt(2) / 6;
// 	transformation_matrix[2][3] = 1;
// 	transformation_matrix[3][0] = 1;
// 	transformation_matrix[3][1] = 1;
// 	transformation_matrix[3][2] = 1;
// 	transformation_matrix[3][2] = 1;
// }

// static t_coordinate	*convert_to_isometric0(t_coordinate *coord,
		// t_param *param)
// {
// 	uint32_t	x_iso;
// 	uint32_t	y_iso;
// 	float		rad;

// 	rad = param->angle * PI / 180;
// 	x_iso = (uint32_t)(((float)coord->x - (float)coord->y + 1) * cos(rad)
// 			- (float)coord->x
// 			+ ((float)param->max_coord->y + (float)param->max_coord->x)
				// * cos(rad));
// 	y_iso = (uint32_t)(((float)coord->x + (float)coord->y + 1) * sin(rad)
// 			- (float)coord->z - (float)coord->x * sin(rad)
// 			+ (float)param->max_coord->z);
// 	coord->x = x_iso;
// 	coord->y = y_iso;
// 	return (coord);
// }

static t_coordinate	*convert_to_isometric1(t_coordinate *coord, t_param *param)
{
	uint32_t	x_iso;
	uint32_t	y_iso;
	float		rad;

	rad = param->angle * PI / 180;
	x_iso = (uint32_t)(((float)coord->x + (float)coord->y) * cos(rad) - (0.5
				* (float)param->min_coord->y));
	y_iso = (uint32_t)((-(float)coord->x + (float)coord->y + 1) * sin(rad)
			- (float)coord->z + param->max_coord->z + param->max_coord->x
			* sin(rad));
	coord->x = x_iso;
	coord->y = y_iso;
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
			all_coordinates[i][j] = convert_to_isometric1(all_coordinates[i][j],
					param);
			if (!all_coordinates[i][j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
