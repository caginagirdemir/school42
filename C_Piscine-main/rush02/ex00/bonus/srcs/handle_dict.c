/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:54:41 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/12 18:38:03 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

bool	check_first3(unsigned int num)
{
	if (num / 100 > 0)
	{
		if (num / 100 > 1 && search(num / 100) == 0)
			return (false);
		if (search(100) == 0)
			return (false);
		num %= 100;
	}
	if (num / 10 > 0)
	{
		if (search(num - num % 10) == 0)
			return (false);
		num %= 10;
	}
	if (num != 0)
		if (search(num) == 0)
			return (false);
	return (true);
}

bool	check_num(unsigned int num)
{
	int	digit;
	int	tens;

	if (num == 0)
		if (search(0) == 0)
			return (false);
	if (num < 1000)
	{
		if (!check_first3(num))
			return (false);
		return (true);
	}
	tens = 1;
	digit = digit_count(num / 10) / 3;
	while (digit-- > 0)
		tens *= 1000;
	if (!check_first3(num / tens))
		return (false);
	if (search(tens) == 0)
		return (false);
	if (!check_num(num % tens))
		return (false);
	return (true);
}

bool	check_line(char *line)
{
	int	i;

	if (line[0] == '\0')
		return (true);
	i = 0;
	if (line[0] < '0' || line[0] > '9')
		return (false);
	while (line[i] != '\0' && line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] != ':')
		return (false);
	i++;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (false);
	while (line[i] != '\0')
	{
		if (line[i] < 32 || line[i] == 127)
			return (false);
		i++;
	}
	return (true);
}

bool	check_dict(unsigned int num)
{
	int				line_counter_desc;
	int				line_reader_desc;
	unsigned int	line_len;
	char			*line;

	line_counter_desc = open(g_dict_name, O_RDONLY);
	line_reader_desc = open(g_dict_name, O_RDONLY);
	if (line_counter_desc < 0 || line_reader_desc < 0)
		return (false);
	while (g_flag)
	{
		line_len = get_line_len(line_counter_desc);
		line = (char *)malloc(line_len * sizeof(char));
		get_line(line_reader_desc, line_len, line);
		if (line_len > 0)
			if (!check_line(line))
				return (false);
	}
	g_flag = true;
	free(line);
	if (!check_num(num))
		return (false);
	return (true);
}

char	*search(unsigned int num)
{
	int				line_counter_desc;
	int				line_reader_desc;
	unsigned int	line_len;
	char			*line;

	line_counter_desc = open(g_dict_name, O_RDONLY);
	line_reader_desc = open(g_dict_name, O_RDONLY);
	if (line_counter_desc < 0 || line_reader_desc < 0)
		return (0);
	while (g_flag)
	{
		line_len = get_line_len(line_counter_desc);
		line = (char *)malloc((line_len + 1) * sizeof(char));
		get_line(line_reader_desc, line_len, line);
		if (num != ft_atoi(line))
			continue ;
		else
			return (get_value(line));
	}
	free(line);
	return (0);
}
