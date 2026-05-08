/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <cagirdem@42f>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:36:12 by cagirdem          #+#    #+#             */
/*   Updated: 2021/11/28 19:09:46 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_char_from_int(int a)
{
	char	char_1;

	char_1 = (a / 10) + 48;
	write(1, &char_1, 1);
	char_1 = (a % 10) + 48;
	write(1, &char_1, 1);
}

void	ft_print_comb2(void)
{
	int		n_1;
	int		n_2;

	n_1 = 0;
	while (n_1 <= 98)
	{
		n_2 = n_1 + 1;
		while (n_2 <= 99)
		{
			write_char_from_int(n_1);
			write(1, " ", 1);
			write_char_from_int(n_2);
			if (n_1 != 98 | n_2 != 99)
			{
				write(1, ", ", 2);
			}
			n_2++;
		}
		n_1++;
	}
}
