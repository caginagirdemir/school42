/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <cagirdem@42f>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:45:00 by cagirdem          #+#    #+#             */
/*   Updated: 2021/11/29 12:40:00 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	char_n;
	char	char_p;

	char_n = 'N';
	char_p = 'P';
	if (n >= 0)
	{
		write(1, &char_p, 1);
	}
	if (n < 0)
	{
		write(1, &char_n, 1);
	}
}
