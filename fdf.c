/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:45:58 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/06 19:06:04 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

# define WIDTH 520
# define HEIGHT 520

typedef struct	s_superv {
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_superv;

// int	create_window(void *mlx, t_superv data)
// {
// 	// mlx_image_to_window(mlx, )
// 	return (EXIT_SUCCESS);
// }

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_randomize(void *param)
{
	t_superv *superv = (t_superv *)param;
	for (uint32_t x = 0; x < superv->image->width; ++x)
	{
		for (uint32_t y = 0; y < superv->image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF,
				rand() % 0xFF,
				rand() % 0xFF,
				rand() % 0xFF
			);
			mlx_put_pixel(superv->image, x, y, color); // prohibited
		}
	}
}

void	ft_hook(void *param)
{
	t_superv *superv;
	
	superv = (t_superv *)param;
	if (mlx_is_key_down(superv->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(superv->mlx);
	if (mlx_is_key_down(superv->mlx, MLX_KEY_UP))
		superv->image->instances[0].y -= 5;
	if (mlx_is_key_down(superv->mlx, MLX_KEY_DOWN))
		superv->image->instances[0].y += 5;
	if (mlx_is_key_down(superv->mlx, MLX_KEY_LEFT))
		superv->image->instances[0].x -= 5;
	if (mlx_is_key_down(superv->mlx, MLX_KEY_RIGHT))
		superv->image->instances[0].x += 5;
}

// void	initialize_super_variable(t_superv *superv)
// {
// 	return ;
// }

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_superv		*superv;

	superv = (t_superv *)malloc(sizeof(t_superv));
	if (!superv)
		return (EXIT_FAILURE);
	// if (argc != 2)
	// 	return(EXIT_FAILURE);
	if (!(superv->mlx = mlx_init(WIDTH, HEIGHT, "42Berlin", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(superv->image = mlx_new_image(superv->mlx, 128, 128)))
	{
		mlx_close_window(superv->mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(superv->mlx, superv->image, 0, 0) == -1)
	{
		mlx_close_window(superv->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(superv->mlx, ft_randomize, superv);
	mlx_loop_hook(superv->mlx, ft_hook, superv);

	mlx_loop(superv->mlx);
	mlx_terminate(superv->mlx);
	return(EXIT_SUCCESS);
}
