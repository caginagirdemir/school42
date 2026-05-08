/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_screen_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:02:10 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 12:14:46 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_x(int i, int j, t_window *data)
{
	t_line	line;

	line.x = j * 64;
	line.y = i * 64;
	line.x1 = j * 64 + 64;
	line.y1 = i * 64 + 64;
	line.color = 0xFFFFFF;
	draw_line(&line, data);
	line.x = j * 64 + 64;
	line.y = i * 64;
	line.x1 = j * 64;
	line.y1 = i * 64 + 64;
	line.color = 0xFFFFFF;
	draw_line(&line, data);
}

void	draw_square(int i, int j, t_window *data)
{
	int	x;
	int	y;
	int	k;
	int	t;

	k = -1;
	t = -1;
	x = j * 64;
	y = i * 64;
	while (++k < 64)
	{
		t = -1;
		while (++t < 64)
			my_mlx_pixel_put(&data->img, x + k, y + t, 0x0FF0000);
	}
}
