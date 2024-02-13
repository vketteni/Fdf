/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:33:53 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/13 15:13:52 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_coordinates(t_coordinate ***all_coordinates)
{
	int	i;
	int	j;

	i = 0;
	while (all_coordinates[i])
	{
		j = 0;
		while (all_coordinates[i][j] != NULL)
			free(all_coordinates[i][j++]);
		free(all_coordinates[i++]);
	}
}

void	terminate_param(t_param *param)
{
	free(param->min_coord);
	free(param->max_coord);
	if (param->all_coordinates)
		free_coordinates(param->all_coordinates);
	if (param->image)
		mlx_delete_image(param->mlx, param->image);
	if (param->mlx)
		mlx_terminate(param->mlx);
	free(param);
}
