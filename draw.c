/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeita <skeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:25:03 by skeita            #+#    #+#             */
/*   Updated: 2025/11/16 12:11:25 by skeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_breswnham(float *x, float *y, bool is_x_breswnham)
{
	if (is_x_breswnham)
		*x += 1;
	else
		*y += 1;
}

void	set_color(float x, float y, t_fdf *data)
{
	if (data->z_matrix[(int)y][(int)x])
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void	breswnham(float x, float y, bool is_x_breswnham, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max_;
	float	x1;
	float	y1;

	x1 = x;
	y1 = y;
	x_breswnham(&x1, &y1, is_x_breswnham);
	zoom_coodinate(&x, &y, data->zoom);
	zoom_coodinate(&x1, &y1, data->zoom);
	set_color(x, y, data);
	isometric(&x, &y, data->z_matrix[(int)y][(int)x]);
	isometric(&x1, &y1, data->z_matrix[(int)y1][(int)x1]);
	offset_coordinate(&x, &y, &x1, &y1);
	max_ = max(mod((x1 - x)), mod((y1 - y)));
	x_step = (x1 - x) / max_;
	y_step = (y1 - y) / max_;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	if (data == NULL)
		return ;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				breswnham(x, y, true, data);
			if (y < data->height - 1)
				breswnham(x, y, false, data);
			x++;
		}
		y++;
	}
}
