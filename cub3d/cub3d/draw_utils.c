/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:28:10 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 11:52:07 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	printf("%d\n", *(unsigned int *)dst);
}

int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_line_with_angle(float x, float y, float angle, t_data *data)
{
	double	x1;
	double	y1;
	float	x_step;
	float	y_step;

	angle = angle * 3.14 / 180;
	printf("angle->%f\n", angle);
	x1 = cos(angle);
	y1 = sin(angle);
	x1 *= 110;
	y1 *= 110;
	x1 += x;
	y1 += y;
	x_step = x1 - x;
	y_step = y1 - y;
	divide_step(&x_step, &y_step);
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (!(x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT))
			my_mlx_pixel_put(data, x, y, 0xFFFFFF);
		x += x_step;
		y += y_step;
	}
}

void	draw_line(t_line *line, t_window *data)
{
	float	x_step;
	float	y_step;

	if (line->color == 0)
		line->color = 0xFFFFFF;
	x_step = line->x1 - line->x;
	y_step = line->y1 - line->y;
	divide_step(&x_step, &y_step);
	while ((int)(line->x - line->x1) || (int)(line->y - line->y1))
	{
		if (!(line->x < 0 || line->y < 0 || \
		line->x >= WIN_WIDTH || line->y >= WIN_HEIGHT))
			my_mlx_pixel_put(&data->img, line->x, line->y, line->color);
		line->x += x_step;
		line->y += y_step;
	}
}
