/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:54:01 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/12 18:22:41 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	digit_count(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
	n /= 10;
	i++;
	}
	return (i);
}

void	write_first3(unsigned int num)
{
	if (num / 100 > 0)
	{
		if (num / 100 > 1)
		{
			ft_putstr(search(num / 100));
			write(1, " ", 1);
		}
		ft_putstr(search(100));
		write(1, " ", 1);
		num %= 100;
	}
	if (num / 10 > 0)
	{
		ft_putstr(search(num - num % 10));
		write(1, " ", 1);
		num %= 10;
	}
	if (num != 0)
		ft_putstr(search(num));
}

void	write_num(unsigned int num, int iteration)
{
	int	digit;
	int	tens;

	if (iteration == 0 && num == 0)
		ft_putstr(search(0));
	if (num < 1000)
	{
		write_first3(num);
		return ;
	}
	tens = 1;
	digit = digit_count(num / 10) / 3;
	while (digit-- > 0)
		tens *= 1000;
	write_first3(num / tens);
	write(1, " ", 1);
	ft_putstr(search(tens));
	write(1, " ", 1);
	write_num(num % tens, iteration + 1);
}

bool	check_validity(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
