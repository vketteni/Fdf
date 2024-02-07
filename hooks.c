/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:52:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/07 08:59:48 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_button_hook(void *param)
{
	t_param *param;
	
	param = (t_param *)param;
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