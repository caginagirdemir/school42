/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:52:48 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/12 15:34:32 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned int	ft_atoi(char *str)
{
	long long		res;
	int				i;

	res = 0;
	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		if (res > 4294967296)
			return (-1);
	}
	return ((unsigned int)res);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

unsigned int	get_line_len(int file_desc)
{
	unsigned int	ret;
	unsigned int	line_len;
	char			c;

	line_len = 0;
	while (true)
	{
		ret = read(file_desc, &c, 1);
		if (ret <= 0 || c == '\n')
			break ;
		line_len++;
	}
	if (ret <= 0)
	{
		g_flag = false;
		return (0);
	}
	return (line_len);
}

void	get_line(int file_desc, int length, char *line)
{
	char		c;

	read(file_desc, line, length);
	line[length] = '\0';
	read(file_desc, &c, 1);
}

char	*get_value(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ':')
		i++;
		i++;
	while (str[i] == ' ')
		i++;
	str = &str[i];
	i = 0;
	while (true)
	{
		while (str[j] != '\0' && str[j] != ' ')
			str[i++] = str[j++];
		while (str[j] != '\0' && str[j] == ' ')
			j++;
		if (str[j] == '\0')
			break ;
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	return (str);
}
