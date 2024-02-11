/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:09:16 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/11 02:02:20 by vketteni         ###   ########.fr       */
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

# define WIDTH 520	* 2
# define HEIGHT 520	* 2
# define PI 3.14159265
# define WINDOW_IMAGE_RATIO 4
# define OFFSET_HEIGHT_RATIO 4
# define BPP sizeof(int32_t)

typedef struct s_bresenham_drawer
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				err2;
}					t_bresenham_drawer;

typedef struct s_fdf_parser
{
	int				fdf_fd;
	char			*line;
	char			**row;
	int				v_pos;
	int				h_pos;
}					t_fdf_parser;

typedef struct s_fdf_checker
{
	int				fdf_fd;
	char			*line;
	char			**line_elements;
	int				elem_per_line;
}					t_fdf_checker;

typedef struct s_coordinate
{
	double			x;
	double			y;
	double			z;
}					t_coordinate;

typedef struct s_param
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_coordinate	***all_coordinates;
	t_coordinate	*min_coord;
	t_coordinate	*max_coord;
	int				fdf_row_num;
	int				fdf_column_num;
	int				angle;
	uint32_t		img_width;
	uint32_t		img_width_offset;
	uint32_t		img_height;
	uint32_t		img_height_offset;
}					t_param;

int					initialize_param(char *fdf_file, t_param *param);
int					initialize_coordinates(int horizontals, int verticals,
						t_param *param);
int					fdf_checker(char *fdf_file);
int					fdf_parse(char *fdf_file, t_param *param);
void				free_coordinates(t_coordinate ***all_coordinates);
void				terminate_param(t_param *param);
void				iso_projection_hook(void *p);
void				button_hook(void *p);
t_coordinate		*create_coordinate(int x, int y, int z, t_param *param);
t_coordinate		*max_coord(t_coordinate ***all_coordinates);
t_coordinate		*min_coord(t_coordinate ***all_coordinates);
int					isometric(t_coordinate ***all_coordinates, t_param *param);
int					initialize_min_max(t_param *param);
void				bresenham(t_coordinate *start, t_coordinate *end,
						t_param *param);
int					normalize_scale_center(t_coordinate ***all_coordinates,
						t_param *param);

/*
 *	Draw Utilities
 */
void				put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
						uint32_t color);
void				draw_pixel(uint8_t *pixel, uint32_t color);
void				draw_line(t_coordinate *start, t_coordinate *end,
						t_param *param);

/*
 *	Utilities
 */
int					fdf_column_num(char *fdf_file);
int					fdf_row_num(char *fdf_file);
void				free_strarr(char **strarr);
int					is_number(char *str);
int					normalize(t_coordinate *coord, t_param *param);
int					center(t_coordinate *coord, t_param *param);
int					scale(t_coordinate *coord, t_param *param);

#endif