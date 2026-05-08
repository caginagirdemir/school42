/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:23:31 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 12:23:43 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image_2(t_window *data, int img_width, int img_height)
{
	data->img_texture_n.img = mlx_xpm_file_to_image(data->mlx, \
	data->texture_paths[0], &img_width, &img_height);
	data->img_texture_n.addr = mlx_get_data_addr(data->img_texture_n.img, \
	&data->img_texture_n.bits_per_pixel, &data->img_texture_n.line_length, \
	&data->img_texture_n.endian);
	data->img_texture_s.img = mlx_xpm_file_to_image(data->mlx, \
	data->texture_paths[1], &img_width, &img_height);
	data->img_texture_s.addr = mlx_get_data_addr(data->img_texture_s.img, \
	&data->img_texture_s.bits_per_pixel, &data->img_texture_s.line_length, \
	&data->img_texture_s.endian);
	data->img_texture_w.img = mlx_xpm_file_to_image(data->mlx, \
	data->texture_paths[2], &img_width, &img_height);
	data->img_texture_w.addr = mlx_get_data_addr(data->img_texture_w.img, \
	&data->img_texture_w.bits_per_pixel, &data->img_texture_w.line_length, \
	&data->img_texture_w.endian);
	data->img_texture_e.img = mlx_xpm_file_to_image(data->mlx, \
	data->texture_paths[3], &img_width, &img_height);
	data->img_texture_e.addr = mlx_get_data_addr(data->img_texture_e.img, \
	&data->img_texture_e.bits_per_pixel, &data->img_texture_e.line_length, \
	&data->img_texture_e.endian);
}

void	load_image(t_window *data)
{
	int	j;

	j = -1;
	while (++j < 4)
	{
		data->texture_paths[j][ft_strlen(data->texture_paths[j]) - 2] = '\0';
		if (open(data->texture_paths[j], O_RDONLY) < 0)
		{
			printf("Error: cannot read a texture file\n");
			exit (1);
		}
	}
	load_image_2(data, 0, 0);
}
