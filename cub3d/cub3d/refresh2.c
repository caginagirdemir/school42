/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:25:18 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 13:27:49 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	divide_step(float *x_step, float *y_step)
{
	int	max;

	max = ft_max(*x_step, *y_step);
	*x_step = *x_step / max;
	*y_step = *y_step / max;
}

void	draw_walls_2(int *img_x, float *sayac_x, float step)
{
	if (*sayac_x >= step * (*img_x + 1))
		*img_x = *img_x + 1;
	*sayac_x = *sayac_x +1;
	if (*img_x == 63)
	{
		*sayac_x = 0;
		*img_x = 0;
	}
}

void	draw_walls_1(t_window *data, int i, int *img_x, float *sayac_x)
{
	int		j;
	float	step;
	int		_y;
	float	sayac_y;
	int		img_y;

	j = 0;
	while (j < 8)
	{
		_y = ((8 * 64) / 2) - data->lineh[i] / 2;
		sayac_y = 0;
		img_y = 0;
		while (_y < ((8 * 64) / 2) - data->lineh[i] / 2 + data->lineh[i])
		{
			step = data->lineh[i] / 64;
			if (*sayac_x < step * *img_x)
				*sayac_x = step * *img_x;
			my_mlx_pixel_put(&data->img, + (i * 8) + j, _y++, \
					get_pixel_color(data->img_texture, *img_x, img_y));
			if (sayac_y++ >= step * (img_y + 1))
				img_y++;
		}
		draw_walls_2(img_x, sayac_x, step);
		j++;
	}
}

void	draw_walls_init(t_window *data)
{
	int		i;
	float	sayac_x;
	int		img_x;

	i = 0;
	img_x = 0;
	sayac_x = 0;
	while (i < 64)
	{
		if (data->ray_target_color[i] == 0x0000FF)
			data->img_texture = &data->img_texture_n;
		else if (data->ray_target_color[i] == 0xFFFF00)
			data->img_texture = &data->img_texture_s;
		else if (data->ray_target_color[i] == 0x00FF00)
			data->img_texture = &data->img_texture_e;
		else if (data->ray_target_color[i] == 0xFFFFFF)
			data->img_texture = &data->img_texture_w;
		draw_walls_1(data, i, &img_x, &sayac_x);
		i++;
	}
}
