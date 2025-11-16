/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeita <skeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:06:38 by skeita            #+#    #+#             */
/*   Updated: 2025/11/16 11:49:25 by skeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

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

int	word_count(const char *s, char c)
{
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

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

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

void	file_matrix(int *z_matrix, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
	{
		z_matrix[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

int	read_file_matrix(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	if (file_name == NULL || data == NULL)
		return (ERROR);
	i = set_matrix(file_name, data);
	if (i == ERROR)
		return (ERROR);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
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
