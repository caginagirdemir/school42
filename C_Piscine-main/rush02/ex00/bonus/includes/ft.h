/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:06:35 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/12 15:37:45 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

char			*g_dict_name;
bool			g_flag;

bool			check_validity(char *num);
bool			check_line(char *line);
bool			check_dict(unsigned int num);
char			*get_value(char *str);
char			*search(unsigned int num);
int				digit_count(unsigned int n);
void			write_first3(unsigned int num);
void			write_num(unsigned int num, int iteration);
unsigned int	ft_atoi(char *str);
void			ft_putstr(char *str);
unsigned int	get_line_len(int file_desc);
void			get_line(int file_desc, int length, char *line);
bool			check_num(unsigned int num);
bool			check_first3(unsigned int num);

#endif
