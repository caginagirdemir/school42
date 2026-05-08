/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 07:16:29 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 12:01:50 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_dup(t_data *src, t_data *dest, t_window *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < 64 * data->map_height)
	{
		x = 0;
		while (x < 64 * data->map_width)
		{
			my_mlx_pixel_put(dest, x, y, get_pixel_color(src, x, y));
			x++;
		}
		y++;
	}
}

void	printf_grid_extra(t_window *data, int x, int y)
{
	while (x < 64 * data->map_width)
	{
		y = 0;
		while (y < 64 * data->map_height)
		{
			if (get_pixel_color(&data->img, x + 1, y) == 0 \
			&& get_pixel_color(&data->img, x - 1, y) > 0)
			{
				my_mlx_pixel_put(&data->img, x, y, 0xFFFFFF);
				my_mlx_pixel_put(&data->img, x + 1, y, 0xFFFFFF);
			}	
			if (get_pixel_color(&data->img, x - 1, y) == 0 \
			&& get_pixel_color(&data->img, x + 1, y) > 0)
			{
				my_mlx_pixel_put(&data->img, x, y, 0x00FF00);
				my_mlx_pixel_put(&data->img, x - 1, y, 0x00FF00);
			}	
			y++;
		}
		x += 64;
	}
}

void	printf_grid_extra_2(t_window *data, int x, int y)
{
	while (y < 64 * data->map_height)
	{
		x = 0;
		while (x < 64 * data->map_width)
		{
			if (get_pixel_color(&data->img, x, y + 1) == 0 \
			&& get_pixel_color(&data->img, x, y - 1) > 0)
			{
				my_mlx_pixel_put(&data->img, x, y, 0x0000FF);
				my_mlx_pixel_put(&data->img, x, y + 1, 0x0000FF);
			}
			if (get_pixel_color(&data->img, x, y - 1) == 0 && \
			get_pixel_color(&data->img, x, y + 1) > 0)
			{
				my_mlx_pixel_put(&data->img, x, y, 0xFFFF00);
				my_mlx_pixel_put(&data->img, x, y - 1, 0xFFFF00);
			}
			x++;
		}
		my_mlx_pixel_put(&data->img, x, y, 0xFFFF00);
		y += 64;
	}
}

void	printf_grid(t_window *data)
{
	int	y;
	int	x;

	printf_grid_extra(data, 63, 0);
	printf_grid_extra_2(data, 0, 63);
	x = 0;
	y = 0;
	while (y < 64 * data->map_height)
	{
		x = 0;
		while (x < 64 * data->map_width)
		{
			if (get_pixel_color(&data->img, x, y) == 0xff0000)
				my_mlx_pixel_put(&data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
	data->copy_img.img = mlx_new_image(data->mlx, data->map_width * 64, \
	data->map_height * 64);
	data->copy_img.addr = mlx_get_data_addr(data->copy_img.img, \
	&data->copy_img.bits_per_pixel, &data->copy_img.line_length, \
	&data->copy_img.endian);
	image_dup(&data->img, &data->copy_img, data);
}

void	printf_background_2d(t_window *data)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < (int)(ft_strlen(data->map[i])))
		{
			if ((int)(data->map[i][j]) == 32)
				draw_x(i, j, data);
			else if ((int)(data->map[i][j]) == 49)
				draw_square(i, j, data);
		}
	}
}
