/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:01:02 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/13 15:40:44 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	coord_iter(t_param *param, int (*f)(t_coordinate *, t_param *))
{
	t_coordinate	***all_coordinates;
	int				i;
	int				j;

	if (!param)
		return (-1);
	all_coordinates = param->all_coordinates;
	if (!all_coordinates)
		return (-1);
	i = 0;
	while (all_coordinates[i])
	{
		j = 0;
		while (all_coordinates[i][j])
		{
			if (f(all_coordinates[i][j++], param) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	rotate_coordinate_y(t_coordinate *coord, t_param *param)
{
	float	current_x;
	float	current_y;
	float	current_z;
	int		degree;

    (void)param;
	degree = 0;
	current_x = coord->x;
	current_y = coord->y;
	current_z = coord->z;
	coord->x = current_x * cos(((ANG_30) * degree) / 30) + current_z
		* sin(((ANG_30) * degree) / 30);
	coord->z = -current_x * sin(((ANG_30) * degree) / 30) + current_z
		* cos(((ANG_30) * degree) / 30);
	return (0);
}

int	rotate_coordinate_x(t_coordinate *coord, t_param *param)
{
	float	current_x;
	float	current_y;
	float	current_z;
	int		degree;

    (void)param;
	degree = 0;
	current_x = coord->x;
	current_y = coord->y;
	current_z = coord->z;
	coord->y = current_y * cos(((ANG_30) * degree) / 30) - current_z
		* sin(((ANG_30) * degree) / 30);
	coord->z = current_y * sin(((ANG_30) * degree) / 30) + current_z
		* cos(((ANG_30) * degree) / 30);
	return (0);
}

int	rotate_coordinate_z(t_coordinate *coord, t_param *param)
{
	float	current_x;
	float	current_y;
	float	current_z;
	int		degree;

    (void)param;
	degree = 0;
	current_x = coord->x;
	current_y = coord->y;
	current_z = coord->z;
	coord->x = current_x * cos(ANG_30) - current_y * sin(ANG_30);
	coord->y = current_x * sin(ANG_30) + current_y * cos(ANG_30);
	return (0);
}

int	rotate_fdf_model(t_param *param)
{
	int	i;

	i = 0;
	while ((i++) < 9)
		coord_iter(param, rotate_coordinate_z);
	i = 0;
	while ((i++) < 1)
		coord_iter(param, rotate_coordinate_x);
	i = 0;
	while ((i++) < 1)
		coord_iter(param, rotate_coordinate_y);
	return (0);
}
