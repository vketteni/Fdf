/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:45:58 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/13 15:08:15 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	create_image(t_param *param)
{
	param->image = mlx_new_image(param->mlx, param->img_width,
			param->img_width);
	if (!(param->image))
	{
		mlx_close_window(param->mlx);
		puts(mlx_strerror(mlx_errno));
		return (-1);
	}
	if (mlx_image_to_window(param->mlx, param->image, 0, 0) == -1)
	{
		mlx_close_window(param->mlx);
		puts(mlx_strerror(mlx_errno));
		return (-1);
	}
	mlx_loop_hook(param->mlx, iso_projection_hook, (void *)param);
	mlx_loop_hook(param->mlx, button_hook, (void *)param);
	mlx_loop(param->mlx);
	mlx_terminate(param->mlx);
	return (0);
}

static int	create_window(t_param *param)
{
	mlx_set_setting(MLX_DECORATED, false);
	param->mlx = mlx_init(WIDTH, HEIGHT, "42Berlin", true);
	if (!(param->mlx))
	{
		puts(mlx_strerror(mlx_errno));
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*param;

	if (argc != 2)
		return (EXIT_FAILURE);
	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (-1);
	if ((initialize_param(argv[1], param) == -1) || create_window(param) == -1
		|| create_image(param) == -1)
	{
		terminate_param(param);
		return (EXIT_FAILURE);
	}
	terminate_param(param);
	return (EXIT_SUCCESS);
}
