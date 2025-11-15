#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define ERROR -1
#define SUCCESS 0
#define OPEN_ERROR -1

int get_height(char *file_name)
{
	char *line;
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (OPEN_ERROR);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int word_count(const char *s, char c) {
    char	**t;
	int		n;
	
	t = ft_split(s, c);
    n = 0;
	while (t && t[n])
	{
		free(t[n]);
		n++;
	}
    free(t);
    return (n);
}

int get_width(char *file_name)
{
	char * line;
	int fd;
	int width;
	
	
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (OPEN_ERROR);
	width = 0;
	get_next_line(fd, &line);
	if (line == NULL)
	{
		free(line);
		close(fd);
		return (0);
	}
	width = word_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void file_matrix(int *z_matrix, char *line)
{
	char **split;
	int i;
	
	split = ft_split(line, ' ');
	if (split == NULL)
		return;
	i = 0;
	while (split[i])
	{
		z_matrix[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

int set_matrix(char *file_name, t_fdf *data)
{
	int i;

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

void free_matrix(t_fdf *data, int i)
{
	while (i > 0)
		free(data->z_matrix[--i]);
	free(data->z_matrix);
	data->z_matrix = NULL;
	data->height = 0;
}

int read_file_matrix(char *file_name, t_fdf *data)
{
	int fd;
	char *line;
	int i;

	if (file_name == NULL || data == NULL)
		return (ERROR);
	i = set_matrix(file_name, data);
	if (i == ERROR)
		return (ERROR);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1){
		free_matrix(data, i);
		return (ERROR);
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		file_matrix(data->z_matrix[i++], line);
		free(line);
	}
	close(fd);
	data->z_matrix[i] = NULL;
	return (SUCCESS);
}
