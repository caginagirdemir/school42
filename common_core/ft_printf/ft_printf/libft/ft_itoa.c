/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:42:54 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/13 12:42:55 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int n)
{
	int	digit;

	digit = !n;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		d_count;
	char	*result;

	sign = n < 0;
	d_count = ft_digit_count(n) + sign;
	result = (char *)malloc(sizeof(char) * (d_count + 1));
	if (!result)
		return (result);
	result[d_count] = 0;
	if (sign)
	{
		*result = '-';
		result[--d_count] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (d_count-- - sign)
	{
		result[d_count] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
