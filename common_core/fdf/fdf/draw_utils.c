/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:18:27 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/16 13:26:55 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(int x, int y, int color, t_mlx *data)
{
	char	*dst;

	dst = data->i.addr + (y * data->i.l_l + x * (data->i.bpp / 8));
	*(unsigned int *)dst = color;
}

void	make_3d(float *x, float *y, int z, t_mlx *data)
{
	(void) x;
	(void) y;
	(void) z;
	(void) data;
	if ((char)data->pers == 0)
	{
		*x = (*x - *y) * sin(0.5);
		*y = (*x + *y) * cos(data->cos) - z;
	}
	else
	{
		*x = *x;
		*y = *y;
	}
}

float	add_prop(float a, char indicator, char c)
{
	if (indicator == 1 && c == 'x')
		return (a + 1);
	else if (indicator == 1 && c == 'y')
		return (a);
	else if (indicator == 0 && c == 'x')
		return (a);
	else if (indicator == 0 && c == 'y')
		return (a + 1);
	return (0);
}

void	add_prop_from_data(float *a, float *b, t_mlx *data)
{
	*a *= data->zoom;
	*a += data->s_x;
	*b *= data->zoom;
	*b += data->s_y;
}

void	divide_step(float *x_step, float *y_step)
{
	int	max;

	max = ft_max(*x_step, *y_step);
	*x_step = *x_step / max;
	*y_step = *y_step / max;
}
