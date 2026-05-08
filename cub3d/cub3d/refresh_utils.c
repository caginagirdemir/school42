/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:28:27 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 13:31:59 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	draw_ceiling_floor_2(t_window *data, int x, int y)
{
	char			**colors;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				color;

	colors = ft_split(data->texture_paths[4], ',');
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	color = (red << 8) | green;
	color = (color << 8) | blue;
	while (x < (8 * 64))
	{
		y = 0;
		while (y < (8 * 64) / 2)
		{
			my_mlx_pixel_put(&data->img, x, y, color);
			y++;
		}
		x++;
	}
	free_2d(colors);
}

void	draw_ceiling_floor_3(t_window *data, int x, int y)
{
	char			**colors;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				color;

	colors = ft_split(data->texture_paths[5], ',');
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	color = (red << 8) | green;
	color = (color << 8) | blue;
	while (x < 8 * 64)
	{
		y = (8 * 64) / 2;
		while (y < 8 * 64)
		{
			my_mlx_pixel_put(&data->img, x, y, color);
			y++;
		}
		x++;
	}
	free_2d(colors);
}

void	draw_ceiling_floor(t_window *data)
{
	draw_ceiling_floor_2(data, 0, 0);
	draw_ceiling_floor_3(data, 0, 0);
}
