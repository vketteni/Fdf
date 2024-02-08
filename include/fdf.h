/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:09:16 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/08 23:55:12 by vketteni         ###   ########.fr       */
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

typedef struct s_fdfparser
{
	int				fdf_fd;
	char			*line;
	char			**row;
	int				v_pos;
	int				h_pos;
}					t_fdf_parser;

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
	t_coordinate	***all_coordinates;
	int				fdf_row_num;
	int				fdf_column_num;
}					t_param;

int					initialize_param(char *fdf_file, t_param *param);
int					initialize_coordinates(int horizontals, int verticals,
						t_param *param);
int					fdf_parse(char *fdf_file, t_param *param);
void				free_coordinates(t_coordinate ***all_coordinates);
void				terminate_param(t_param *param);

/*
 *	utilities
 */
int					fdf_column_num(char *fdf_file);
int					fdf_row_num(char *fdf_file);
void				free_strarr(char **strarr);
void				ft_button_hook(t_param *param);

#endif