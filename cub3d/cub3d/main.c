/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2222/25/23 17:37:32 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 12:27:51 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	deal_key(int key, t_window *data)
{
	if (key == 53)
		exit(1);
	else if (key == 0)
		refresh(data, 3);
	else if (key == 13)
		refresh(data, 1);
	else if (key == 1)
		refresh(data, 0);
	else if (key == 2)
		refresh(data, 2);
	return (0);
}

int	main_error(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("File not found!\n");
		exit(1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	t_window	*window;
	int			fd;

	fd = main_error(argc, argv);
	window = (t_window *)malloc(sizeof(t_window));
	window->mlx = mlx_init();
	if (fill_struct(window, fd))
		return (printf("Cub File Instructure Error\n"));
	window->mlx_win = mlx_new_window(window->mlx, \
	8 * 64 + 1 * 2, 8 * 64 + 1, "cub3d");
	window->img.img = mlx_new_image(window->mlx, window->map_width * 64 * 2, \
	window->map_height * 64 + 1);
	window->img.addr = mlx_get_data_addr(window->img.img, \
	&window->img.bits_per_pixel, &window->img.line_length, \
	&window->img.endian);
	load_image(window);
	printf_background_2d(window);
	printf_grid(window);
	refresh(window, 4);
	mlx_put_image_to_window(window->mlx, window->mlx_win, \
	window->img.img, 0, 0);
	mlx_key_hook(window->mlx_win, deal_key, window);
	mlx_loop(window->mlx);
}
