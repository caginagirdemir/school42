/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:22:42 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/16 12:28:01 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close (fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free (line);
	close (fd);
	return (width);
}

void	fill_matrix(int	*z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free (nums);
}

/*
 * önce dosya okuayarak yükseklik ve genislik degerlerini getirdik
 * genislik ve yükseklik ile z_matrix i olusturduk
 * fill_matrix ile iki boyutlu z_matrix i dosyadan doldurduk
 */

void	read_file_extended(char *file_name, t_mlx *data)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		write(1, "error\n", 6);
		free(data);
		exit(1);
	}
	close(fd);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
}

void	read_file(char *file_name, t_mlx *data)
{
	int		fd;
	char	*line;
	int		i;

	read_file_extended(file_name, data);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
