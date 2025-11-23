/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeita <skeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:32:39 by skeita            #+#    #+#             */
/*   Updated: 2025/11/16 11:33:26 by skeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	advance_step(float *x, float *y, float x_step, float y_step)
{
	*x += x_step;
	*y += y_step;
}

int	init_mlx_and_window(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FDF");
	if (data->win_ptr == NULL)
		return (ERROR);
	return (SUCCESS);
}

int	init_image(t_fdf *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (data->img_ptr == NULL)
		return (ERROR);
	data->img_data = mlx_get_data_addr(
			data->img_ptr, &data->bpp, &data->size_line, &data->endian);
	return (SUCCESS);
}