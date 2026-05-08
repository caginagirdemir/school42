/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:21:24 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/20 15:34:22 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_negative(int *value)
{
	int	i;

	i = 0;
	if (*value == INT_MIN)
	{
		i = 1;
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		*value = 147483648;
		i++;
	}
	else if (*value < 0)
	{
		ft_putchar_fd('-', 1);
		*value *= -1;
		i++;
	}
	return (i);
}

int	ft_decimal_format(int value)
{
	int		i;
	char	*str;

	i = ft_is_negative(&value);
	str = ft_itoa_base(value, "0123456789");
	i += ft_string_format(str);
	free(str);
	return (i);
}
