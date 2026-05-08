/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:43:55 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/16 15:04:25 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_max(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	else
		return (b);
	return (0);
}

void	set_color(float z, float z1, t_mlx *data)
{
	if (z == 0 && z1 == 0)
		data->color = 0xffffff;
	else if (z == 10 && z1 == 10)
		data->color = 0x78C0E0;
	else if (z == 9 && z1 == 9)
		data->color = 0xFF5C8D;
	else if (z == 8 && z1 == 8)
		data->color = 0xFF5C8D;
	else
		data->color = 0xffffff;
}

float	get_z(float b, float a, int i, t_mlx *data)
{
	float	ret_val;

	if (i == 0)
		ret_val = data->z_matrix[(int)b][(int)a];
	else
		ret_val = data->z_matrix[(int)b][(int)a];
	return (ret_val);
}

void	draw_line(float x, float y, char indicator, t_mlx *data)
{
	float	x1;
	float	y1;
	float	x_step;
	float	y_step;
	float	z[2];

	x1 = add_prop(x, indicator, 'x');
	y1 = add_prop(y, indicator, 'y');
	z[0] = get_z(y, x, 0, data);
	z[1] = get_z(y1, x1, 1, data);
	add_prop_from_data(&x, &y, data);
	add_prop_from_data(&x1, &y1, data);
	make_3d(&x, &y, z[0], data);
	make_3d(&x1, &y1, z[1], data);
	set_color(z[0], z[1], data);
	x_step = x1 - x;
	y_step = y1 - y;
	divide_step(&x_step, &y_step);
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (!(x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT))
			my_mlx_pixel_put(x, y, data->color, data);
		x += x_step;
		y += y_step;
	}
}

void	draw_all_window(t_mlx *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_line(x, y, 1, data);
			if (y < data->height - 1)
				draw_line(x, y, 0, data);
			x++;
		}
		y++;
	}
}
