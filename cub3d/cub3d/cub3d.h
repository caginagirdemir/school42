/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:40:13 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 13:32:38 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 8
# define WIN_HEIGHT 8

# include <math.h>
# include "./minilibx_mac/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_line {
	float			x;
	float			y;
	float			x1;
	float			y1;
	unsigned int	color;
}	t_line;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_window {
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	t_data			*img_texture;
	t_data			img_texture_n;
	t_data			img_texture_s;
	t_data			img_texture_w;
	t_data			img_texture_e;
	t_data			copy_img;
	float			ray_x[64];
	float			ray_y[64];
	int				ray_target_color[64];
	float			lineh[64];
	float			player_position_x;
	float			player_position_y;
	short int		perspective_angle;
	char			**texture_paths;
	char			**map;
	int				map_height;
	int				map_width;
}	t_window;

void	printf_background_2d(t_window *data);
void	printf_grid(t_window *data);
void	image_dup(t_data *src, t_data *dest, t_window *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line_with_angle(float x, float y, float angle, t_data *data);
void	draw_line(t_line *line, t_window *data);
int		ft_max(int a, int b);
void	refresh(t_window *data, int direction);
void	print_pixel_color(t_data *data, int x, int y);
int		get_pixel_color(t_data *data, int x, int y);
void	divide_step(float *x_step, float *y_step);

int		fill_struct(t_window *data, const int fd);
char	*get_next_line(int fd);
int		get_path_headers(int fd, char **paths);
void	draw_x(int i, int j, t_window *data);
void	draw_square(int i, int j, t_window *data);
void	load_image(t_window *data);
void	free_2d(char **arr);
void	draw_ceiling_floor(t_window *data);
void	draw_walls_init(t_window *data);

#endif
