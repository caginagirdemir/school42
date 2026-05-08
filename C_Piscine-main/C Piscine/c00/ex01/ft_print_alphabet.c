/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <cagirdem@42f>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:42:00 by cagirdem          #+#    #+#             */
/*   Updated: 2021/11/27 23:51:00 by cagirdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	alphabet;

	alphabet = 'a';
	while (alphabet <= 'z')
	{
		ft_putchar(alphabet);
		alphabet++;
	}
}
