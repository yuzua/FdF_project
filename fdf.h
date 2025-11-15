#ifndef FDF_CODE_H
#define FDF_CODE_H

#include "get_next_line/get_next_line.h"
// #include "libft/libft.h"
// #include "minilibx_macos/mlx.h"

typedef struct
{
	int width;
	int height;
	int **z_matrix;
	int zoom;
	int color;

	void *mlx_ptr;
	void *win_ptr;
} t_fdf;

int read_file_matrix(char *file_name, t_fdf *data);
void breswnham(float x, float y, float x1, float y1, t_fdf *data);
void draw_map(t_fdf *data);

#endif