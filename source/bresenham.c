/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:51:37 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/10 20:06:51 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_bresenham_drawer	*initialize_bresenham_drawer(t_coordinate *start,
		t_coordinate *end)
{
	t_bresenham_drawer	*drawer;

	drawer = (t_bresenham_drawer *)malloc(sizeof(t_bresenham_drawer));
	if (!drawer)
		return (NULL);
	drawer->x0 = (int)round(start->x);
	drawer->y0 = (int)round(start->y);
	drawer->x1 = (int)round(end->x);
	drawer->y1 = (int)round(end->y);
	drawer->dx = abs(drawer->x1 - drawer->x0);
	drawer->dy = abs(drawer->y1 - drawer->y0);
	if (drawer->x0 < drawer->x1)
		drawer->sx = 1;
	else
		drawer->sx = -1;
	if (drawer->y0 < drawer->y1)
		drawer->sy = 1;
	else
		drawer->sy = -1;
	drawer->err = drawer->dx - drawer->dy;
	drawer->err2 = 2 * drawer->err;
	return (drawer);
}

void	bresenham(t_coordinate *start, t_coordinate *end, t_param *param)
{
	t_bresenham_drawer *drawer;

	drawer = initialize_bresenham_drawer(start, end);
	if (!drawer)
		return ;
	while (drawer->x0 != drawer->x1 || drawer->y0 != drawer->y1)
	{
		put_pixel(param->image, (uint32_t)drawer->x0, (uint32_t)drawer->y0,
			0xFFFFFFFF);
		drawer->err2 = 2 * drawer->err;
		if (drawer->err2 > -drawer->dy)
		{
			drawer->err -= drawer->dy;
			drawer->x0 += drawer->sx;
		}
		if (drawer->err2 < drawer->dx)
		{
			drawer->err += drawer->dx;
			drawer->y0 += drawer->sy;
		}
	}
}