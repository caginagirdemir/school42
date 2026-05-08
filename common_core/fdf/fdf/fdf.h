/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:14:15 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/16 12:33:54 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "./minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
/*
 * -img_ptr to store the return value of mlx_new_image
 * -data to store the return value of mlx_get_data_addr
 * */
typedef struct s_img
{
	void	*i;
	char	*addr;
	int		l_l;
	int		bpp;
	int		end;
}	t_img;

typedef struct s_mlx
{
	int		**z_matrix;
	float	cos;
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		s_x;
	int		s_y;
	void	*mlx_ptr;
	void	*win;
	t_img	i;
	char	pers;
}	t_mlx;

void	draw_line(float x, float y, char indicator, t_mlx *data);
void	draw_all_window(t_mlx *data);
void	set_color(float z, float z1, t_mlx *data);
void	read_file(char *file_name, t_mlx *data);
int		ft_max(int a, int b);
void	my_mlx_pixel_put(int x, int y, int color, t_mlx *data);
void	make_3d(float *x, float *y, int z, t_mlx *data);
float	add_prop(float a, char indicator, char c);
void	add_prop_from_data(float *a, float *b, t_mlx *data);
void	divide_step(float *x_step, float *y_step);
#endif
