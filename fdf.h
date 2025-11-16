/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeita <skeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:06:56 by skeita            #+#    #+#             */
/*   Updated: 2025/11/16 12:01:52 by skeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>	
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR -1
# define SUCCESS 0
# define OPEN_ERROR -1
# define LINUX_ESC_KEY 0xff1b
# define MACOS_ESC_KEY 53
# define WINDOWS_ESC_KEY 0x1B
# define CLOSE_BUTTON 17

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

int		get_height(char *file_name);
int		word_count(const char *s, char c);
int		get_width(char *file_name);
void	file_matrix(int *z_matrix, char *line);
int		read_file_matrix(char *file_name, t_fdf *data);

int		set_matrix(char *file_name, t_fdf *data);
void	free_matrix(t_fdf *data, int i);

void	isometric(float *x, float *y, float z);
void	zoom_coodinate(float *a, float *b, int zoom);
void	offset_coordinate(float *x, float *y, float *x1, float *y1);

float	mod(float a);
float	max(float a, float b);
void	advance_step(float *x, float *y, float x_step, float y_step);

void	x_breswnham(float *x, float *y, bool is_x_breswnham);
void	set_color(float x, float y, t_fdf *data);
void	breswnham(float x, float y, bool is_x_breswnham, t_fdf *data);
void	draw_map(t_fdf *data);

int		close_key_handler(int keycode, t_fdf *data);
int		close_handler(void *param);
int		set_data(t_fdf *data, char *file_name);
void	free_data(t_fdf *data);

#endif