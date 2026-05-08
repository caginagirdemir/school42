/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:17:42 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/16 13:02:12 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	refresh(t_mlx *d)
{
	mlx_clear_window(d->mlx_ptr, d->win);
	d->i.i = mlx_new_image(d->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	d->i.addr = mlx_get_data_addr(d->i.i, &d->i.bpp, &d->i.l_l, &d->i.end);
	draw_all_window(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win, d->i.i, 0, 0);
}

int	deal_key(int key, t_mlx *data)
{
	if (key == 53)
	{
		free(data);
		exit(1);
	}
	else if (key == 0)
		data->cos -= 0.1;
	else if (key == 12)
		data->cos += 0.1;
	else if (key == 123)
		data->s_x -= 10;
	else if (key == 126)
		data->s_y -= 10;
	else if (key == 125)
		data->s_y += 10;
	else if (key == 124)
		data->s_x += 10;
	else if (key == 13)
		data->pers = 1;
	else if (key == 1)
		data->pers = 0;
	refresh(data);
	return (0);
}

int	mouse_hook(int mouse_key, int x, int y, t_mlx *data)
{
	(void) x;
	(void) y;
	if (mouse_key == 5)
	{
		data->zoom += 5;
		refresh(data);
	}
	else if (mouse_key == 4)
	{
		data->zoom -= 5;
		refresh(data);
	}
	else if (mouse_key == 3)
	{
		data->zoom = 30;
		refresh(data);
	}
	return (0);
}

void	set_initial_setting(t_mlx *data)
{
	data->zoom = 30;
	data->cos = 0.5;
	data->pers = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	*m;

	if (argc == 2 || !(argv[2]))
	{
		m = (t_mlx *)malloc(sizeof(t_mlx));
		read_file(argv[1], m);
		m->mlx_ptr = mlx_init();
		m->win = mlx_new_window(m->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
		set_initial_setting(m);
		m->i.i = mlx_new_image(m->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		m->i.addr = mlx_get_data_addr(m->i.i, &m->i.bpp, &m->i.l_l, &m->i.end);
		draw_all_window(m);
		mlx_put_image_to_window(m->mlx_ptr, m->win, m->i.i, 0, 0);
		mlx_key_hook(m->win, deal_key, m);
		mlx_mouse_hook(m->win, mouse_hook, m);
		mlx_loop(m->mlx_ptr);
	}
	else
		write(1, "error\n", 6);
	return (0);
}
