/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:52:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/10 15:41:39 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	button_hook(void *p)
{
	t_param	*param;

	param = (t_param *)p;
	if (mlx_is_key_down(param->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param->mlx);
	if (mlx_is_key_down(param->mlx, MLX_KEY_UP))
		param->image->instances[0].y -= 5;
	if (mlx_is_key_down(param->mlx, MLX_KEY_DOWN))
		param->image->instances[0].y += 5;
	if (mlx_is_key_down(param->mlx, MLX_KEY_LEFT))
		param->image->instances[0].x -= 5;
	if (mlx_is_key_down(param->mlx, MLX_KEY_RIGHT))
		param->image->instances[0].x += 5;
}

void	iso_projection_hook(void *p)
{
	t_param	*param;
	int	i;
	int	j;

	i = 0;
	param = (t_param *)p;
	while (param->all_coordinates[i])
	{
		j = 0;
		while (param->all_coordinates[i][j])
		{
			draw_line(param->all_coordinates[i][j], param->all_coordinates[i][j + 1], param);
			if (param->all_coordinates[i + 1])
				draw_line(param->all_coordinates[i][j], param->all_coordinates[i + 1][j], param);
			j++;
		}
		i++;
	}
}