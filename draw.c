#include "fdf.h"
#include "mlx.h"
#include <math.h>

#define MAX(a, b) ((a > b) ? a : b)
#define MOD(a) ((a < 0 )? -a : a)

// float mod(float a)
// {
//     return ((a < 0 )? -a : a);
// }

void	isometric(float *x, float *y, float z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI / 6);
	*y = (prev_x + prev_y) * sin(M_PI / 6) - z;
}

void	zoom_coodinate(float *a, float *b, int zoom)
{
	*x *= zoom;
	*y *= zoom;
}

void	xxx_coodinate(float *x, float *y, float *x1, float *y1)
{
	*x += 150;
	*y += 150;
	*x1 += 150;
	*y1 += 150;
}

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

void	advance_step(float *x, float *y, float x_step, float y_step)
{
	*x += x_step;
	*y += y_step;
}

void	breswnham(float x, float y, bool is_x_breswnham, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
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
	xxx_coodinate(&x, &y, &x1, &y1);
	max = MAX(MOD((x1 - x)), MOD((y1 - y)));
	x_step = (x1 - x) / max;
	y_step = (y1 - y) / max;
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
