/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeita <skeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:29:18 by skeita            #+#    #+#             */
/*   Updated: 2025/11/16 11:46:33 by skeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, float z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI / 6);
	*y = (prev_x + prev_y) * sin(M_PI / 6) - z;
}

void	offset_coordinate(float *x, float *y, float *x1, float *y1)
{
	*x += WIN_W / 2;
	*y += WIN_H / 2;
	*x1 += WIN_W / 2;
	*y1 += WIN_H / 2;
}

void	zoom_coodinate(float *a, float *b, int *z, int zoom)
{
	*a *= zoom;
	*b *= zoom;
	*z *= zoom;
}

void	center_coordinate(float *x, float *y, t_fdf *data)
{
	*x -= (float)data->width / 2.0f;
	*y -= (float)data->height / 2.0f;
}
