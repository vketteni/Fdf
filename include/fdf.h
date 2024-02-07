/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:09:16 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/07 19:31:10 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 520
# define HEIGHT 520

typedef struct s_coordinate
{
	int				x;
	int				y;
	int				z;
}					t_coordinate;

typedef struct s_param
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_coordinate	**all_coordinates;
}					t_param;

void				ft_button_hook(void *param);

#endif