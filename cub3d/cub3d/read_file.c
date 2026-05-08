/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:57:16 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 12:57:20 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_path_headers_2(int fd, char **paths, char **header_names, int i)
{
	char	*str;
	char	**texture_files;

	while (++i < 6)
	{
		if (i == 4)
		{
			str = get_next_line(fd);
			if (!(str[0] == '\n' || str[0] == 13) || ft_strlen(str) > 2)
			{
				printf("Error: Map file struct fail\n");
				exit(1);
			}
			free(str);
		}
		str = get_next_line(fd);
		texture_files = ft_split(str, ' ');
		free(str);
		if (ft_strncmp(texture_files[0], header_names[i], \
		sizeof(header_names[i])) != 0)
			return (1);
	paths[i] = ft_strdup(texture_files[1]);
		free_2d(texture_files);
	}
	return (0);
}

int	get_path_headers(int fd, char **paths)
{
	char	*str;
	char	*header_names[6];

	header_names[0] = "NO";
	header_names[1] = "SO";
	header_names[2] = "WE";
	header_names[3] = "EA";
	header_names[4] = "F";
	header_names[5] = "C";
	if (get_path_headers_2(fd, paths, header_names, -1))
		return (1);
	str = get_next_line(fd);
	if (!(str[0] == '\n' || str[0] == 13) || ft_strlen(str) > 2)
	{
		printf("Error: Map file struct fail\n");
		exit(1);
	}
	free(str);
	return (0);
}

int	fill_map(int fd, t_window *data)
{
	char	*str[50];
	int		i;
	int		max_line_len;

	max_line_len = 0;
	i = 0;
	while (1)
	{
		str[i] = get_next_line(fd);
		if (!str[i])
			break ;
		if ((int)(ft_strlen(str[i])) > max_line_len)
			max_line_len = ft_strlen(str[i]) - 2;
		i++;
	}
	data->map_height = i;
	data->map_width = max_line_len;
	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	i = -1;
	while (++i < (int)(data->map_height))
		data->map[i] = str[i];
	return (0);
}

void	fill_player_position(t_window *data, char c, int i, int j)
{
	data->player_position_x = (j * 64) + 32;
	data->player_position_y = (i * 64) + 32;
	if (c == 87)
		data->perspective_angle = 0;
	else if (c == 69)
		data->perspective_angle = 180;
	else if (c == 78)
		data->perspective_angle = 270;
	else if (c == 83)
		data->perspective_angle = 90;
}

int	fill_struct(t_window *data, const int fd)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	j = -1;
	data->texture_paths = (char **)malloc(sizeof(char *) * 6);
	if (get_path_headers(fd, data->texture_paths))
		return (1);
	if (fill_map(fd, data))
		return (1);
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < (int)(ft_strlen(data->map[i])))
		{
			c = data->map[i][j];
			if (c == 78 || c == 83 || c == 87 || c == 69)
				fill_player_position(data, c, i, j);
		}
	}
	return (0);
}
