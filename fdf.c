/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:45:58 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/07 19:56:25 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_param	*parse_map(char *map_file, t_param *param)
{
	int		map_fd;
	char	*line;
	char	**row;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		line = ft_strtrim(line, "\n ");
		if (line == NULL)
		{
			close (map_fd);
			return (NULL);
		}
		row = ft_split(line, ' ');
		if (row == NULL)
		{
			close (map_fd);
			free(line);
			return (NULL);
		}
		while (row[x] != NULL)
		{
			param->all_coordinates[y][x].x = ft_atoi(x);
			param->all_coordinates[y][x].y = ft_atoi(y);
			param->all_coordinates[y][x].z = ft_atoi(row[x]);
			x++;
		}
		y++;
		free(line);
		line = get_next_line(map_fd);
	}
	close (map_fd);
	return (param);
}

int	initialize_coordinates(char *map_file, t_param *param)
{
	int		number_of_lines;
	int		points_per_line;
	char	**first_line;
	int		map_fd;

	number_of_lines = 0;
	points_per_line = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	first_line = ft_split(get_next_line(map_fd), ' ');
	if (first_line == NULL)
		return (-1);
	while (first_line[points_per_line] != '\n')
		points_per_line++;
	number_of_lines++;
	while (get_next_line(map_fd))
		number_of_lines++;
	close(map_fd);
	param->all_coordinates = (t_coordinate **)malloc((sizeof(t_coordinate *)
				* number_of_lines) + (sizeof(t_coordinate) * (number_of_lines
					* points_per_line)));
	if (param->all_coordinates == NULL)
		return (-1);
}

int	initialize_param(int argc, char **argv, t_param *param)
{
	int		map_fd;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (-1);
	if (initialize_coordinates(argv[1], param) == -1)
		return (-1);
	if (parse_map(argv[1], param) == NULL)
		return (-1);
	
}

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

void	free_param(t_param *param)
{
	if (param->all_coordinates)
		free_coordinates(param->all_coordinates);
	if (param->image)
		mlx_delete_image(param->mlx, param->image);
	if (param->mlx)
		mlx_terminate(param->mlx);
	free(param);
}

int	main(int argc, char **argv)
{
	t_param	*param;

	param = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	if (initialize_param(argc, argv, param) == -1)
	{
		free_param(param);
		return (EXIT_FAILURE);
	}
	// param->mlx = mlx_init(WIDTH, HEIGHT, "42Berlin", true);
	// if (!(param->mlx))
	// {
	// 	puts(mlx_strerror(mlx_errno));
	// 	free_param(param);
	// 	return (EXIT_FAILURE);
	// }
	// param->image = mlx_new_image(param->mlx, 128, 128);
	// if (!(param->image))
	// {
	// 	mlx_close_window(param->mlx);
	// 	free_param(param);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(param->mlx, param->image, 0, 0) == -1)
	// {
	// 	mlx_close_window(param->mlx);
	// 	free_param(param);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	// mlx_loop(param->mlx);
	// mlx_terminate(param->mlx);
	return (EXIT_SUCCESS);
}
