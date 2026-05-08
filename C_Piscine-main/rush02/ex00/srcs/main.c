/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:32:25 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/12 14:54:33 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

bool	check_errors(char *num)
{
	if (!check_validity(num) || ft_atoi(num) == (unsigned int)-1)
	{
		ft_putstr("Error\n");
		return (false);
	}
	if (!check_dict(ft_atoi(num)))
	{
		ft_putstr("Dict Error\n");
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	g_flag = true;
	g_dict_name = "numbers.dict";
	if (argc < 2)
	{
		g_dict_name = NULL;
		while (true)
			read(0, NULL, 0);
	}
	if (argc == 2)
	{
		if (!check_errors(argv[1]))
			return (1);
		g_flag = true;
		write_num(ft_atoi(argv[1]), 0);
	}
	if (argc == 3)
	{
		g_dict_name = argv[1];
		if (!check_errors(argv[2]))
			return (1);
		g_flag = true;
		write_num(ft_atoi(argv[2]), 0);
	}
	return (0);
}
