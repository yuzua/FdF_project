/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeita <skeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:06:44 by skeita            #+#    #+#             */
/*   Updated: 2025/11/16 12:11:47 by skeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_key_handler(int keycode, t_fdf *data)
{
	if (keycode != LINUX_ESC_KEY && keycode != MACOS_ESC_KEY
		&& keycode != WINDOWS_ESC_KEY)
		return (0);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_data(data);
	exit(0);
}

int	close_handler(void *param)
{
	t_fdf	*data;

	if (param == NULL)
		return (0);
	data = (t_fdf *)param;
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_data(data);
	exit(0);
}

int	set_data(t_fdf *data, char *file_name)
{
	if (data == NULL || file_name == NULL)
		return (ERROR);
	if (read_file_matrix(file_name, data) == ERROR)
	{
		free_data(data);
		return (ERROR);
	}
	if (init_mlx_and_window(data) == ERROR)
	{
		free_data(data);
		return (ERROR);
	}
	if (init_image(data) == ERROR)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_data(data);
		return (ERROR);
	}
	data->zoom = 20;
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY, 0);
	if (fd == -1)
		return (1);
	close(fd);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (data == NULL)
		return (1);
	if (set_data(data, argv[1]) == ERROR)
		return (1);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, CLOSE_BUTTON, 0L, close_handler, data);
	mlx_key_hook(data->win_ptr, close_key_handler, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

void	free_data(t_fdf *data)
{
	int	i;

	if (data == NULL)
		return ;
	i = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	if (data->z_matrix != NULL)
		free(data->z_matrix);
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	free(data);
}
