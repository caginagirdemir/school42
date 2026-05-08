/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:29:46 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 13:19:03 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	refresh_direction(t_window *data, int direction, float *ang, float t)
{
	if (direction == 1)
	{
		data->player_position_x += cos(data->perspective_angle * t) * 20;
		data->player_position_y += sin(data->perspective_angle * t) * 20;
	}
	else if (direction == 0)
	{
		data->player_position_y -= sin(data->perspective_angle * t) * 20;
		data->player_position_x -= cos(data->perspective_angle * t) * 20;
	}
	else if (direction == 3)
	{
		data->perspective_angle -= 5;
		if (data->perspective_angle < 0)
			data->perspective_angle += 360;
	}
	else if (direction == 2)
	{
		data->perspective_angle += 5;
		if (data->perspective_angle > 360)
			data->perspective_angle -= 360;
	}
	*ang = data->perspective_angle - (60.00 / 64.00) * 32;
}

void	find_intersect_point(t_window *data, float *tmp_angle)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		*tmp_angle += (60.00 / 64.00);
		data->ray_x[i] = data->player_position_x;
		data->ray_y[i] = data->player_position_y;
		while (1)
		{
			data->ray_x[i] += cos(*tmp_angle * 3.14 / 180);
			data->ray_y[i] += sin(*tmp_angle * 3.14 / 180);
			if (get_pixel_color(&data->img, data->ray_x[i], data->ray_y[i]) > 0)
			{
				data->ray_target_color[i] = get_pixel_color(&data->img, \
				data->ray_x[i], data->ray_y[i]);
				break ;
			}
		}
		i++;
	}
}

void	hlines_calc(t_window *data, float *tmp_angle)
{
	int		i;
	float	dist;
	float	fisheye_angle;

	i = 0;
	*tmp_angle = data->perspective_angle;
	*tmp_angle -= (60.00 / 64.00) * 32;
	while (i < 64)
	{
		dist = sqrt(pow((data->ray_x[i] - data->player_position_x), 2) + \
		pow((data->ray_y[i] - data->player_position_y), 2));
		fisheye_angle = data->perspective_angle - \
		(*tmp_angle + (60.00 / 64.00));
		*tmp_angle += 60.00 / 64.00;
		if (fisheye_angle < 0)
			fisheye_angle += 2 * 3.14;
		else if (fisheye_angle > 2 * 3.14)
			fisheye_angle -= 2 * 3.14;
		dist *= cos(fisheye_angle * 3.14 / 180);
		data->lineh[i] = (64 * (64 * WIN_HEIGHT)) / dist;
		if (data->lineh[i] > (64 * WIN_HEIGHT))
			data->lineh[i] = (64 * WIN_HEIGHT);
		i++;
	}
}

void	refresh(t_window *data, int direction)
{
	float	tmp_angle;

	mlx_clear_window(data->mlx, data->mlx_win);
	data->img.img = mlx_new_image(data->mlx, data->map_width * 64 * 2, \
	data->map_height * 64);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, \
	&data->img.endian);
	image_dup(&data->copy_img, &data->img, data);
	refresh_direction(data, direction, &tmp_angle, 3.14 / 180);
	find_intersect_point(data, &tmp_angle);
	hlines_calc(data, &tmp_angle);
	draw_ceiling_floor(data);
	draw_walls_init(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
