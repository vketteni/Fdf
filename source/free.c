/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:33:53 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/14 14:59:34 by vketteni         ###   ########.fr       */
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
	free(param);
}
