#include "fdf.h"
#include "mlx.h"
#include <math.h>

#define MAX(a, b) ((a > b) ? a : b)
#define MOD(a) ((a < 0 )? -a : a)

float mod(float a)
{
    return ((a < 0 )? -a : a);
}

void isometric(float *x, float *y, float z)
{
    float prev_x;
    float prev_y;

    prev_x = *x;
    prev_y = *y;
    *x = (prev_x - prev_y) * cos(M_PI / 6);
    *y = (prev_x + prev_y) * sin(M_PI / 6) - z;
}

void breswnham(float x, float y, float x1, float y1, t_fdf *data)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    data->color = (z) ? 0xe80c0c : 0xffffff;
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    x += 150;
    y += 150;
    x1 += 150;
    y1 += 150;
    x_step = x1 - x;
    y_step = y1 - y;
    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    }
}

void draw_map(t_fdf *data)
{
    int x;
    int y;

    if (data == NULL)
        return;
    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                breswnham(x, y, x + 1, y, data);
            if (y < data->height - 1)
                breswnham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}