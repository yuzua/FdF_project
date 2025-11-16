/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeita <skeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:14:17 by skeita            #+#    #+#             */
/*   Updated: 2025/11/16 11:59:15 by skeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_matrix(char *file_name, t_fdf *data)
{
	int	i;

	if (file_name == NULL || data == NULL)
		return (ERROR);
	data->width = get_width(file_name);
	data->height = get_height(file_name);
	if (data->width <= 0 || data->height <= 0)
		return (ERROR);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (data->z_matrix == NULL)
		return (ERROR);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (data->z_matrix[i++] == NULL)
		{
			while (i > 0)
				free(data->z_matrix[--i]);
			free(data->z_matrix);
			return (ERROR);
		}
	}
	return (i);
}

void	free_matrix(t_fdf *data, int i)
{
	while (i > 0)
		free(data->z_matrix[--i]);
	free(data->z_matrix);
	data->z_matrix = NULL;
	data->height = 0;
}

