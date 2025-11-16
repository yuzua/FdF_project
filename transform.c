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
	*x += 150;
	*y += 150;
	*x1 += 150;
	*y1 += 150;
}

void	zoom_coodinate(float *a, float *b, int zoom)
{
	*a *= zoom;
	*b *= zoom;
}
