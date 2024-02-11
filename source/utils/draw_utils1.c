/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:08:28 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/11 01:21:11 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_pixel(uint8_t *pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

void	put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	uint8_t	*pixelstart;

	if (x > image->width)
	{
		printf("x: %d ", x);
		ft_putendl_fd("Pixel (x value) is out of bounds.", 2);
		exit(EXIT_FAILURE);
	}
	if (y > image->height)
	{
		printf("y: %d ", y);
		ft_putendl_fd("Pixel (y value) is out of bounds.", 2);
		exit(EXIT_FAILURE);
	}

	pixelstart = &image->pixels[(y * image->width + x) * BPP];
	draw_pixel(pixelstart, color);
}

void	draw_line(t_coordinate *start, t_coordinate *end, t_param *param)
{
	if (!start || !end || !param)
		return ;
	bresenham(start, end, param);
}
