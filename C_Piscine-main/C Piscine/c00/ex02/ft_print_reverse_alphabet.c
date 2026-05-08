/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <cagirdem@42f>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:45:00 by cagirdem          #+#    #+#             */
/*   Updated: 2021/11/28 15:30:15 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	alphabet;

	alphabet = 'z';
	while (alphabet >= 'a')
	{
		ft_putchar(alphabet);
		alphabet--;
	}
}
