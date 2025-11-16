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
