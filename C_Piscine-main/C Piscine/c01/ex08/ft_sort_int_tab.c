/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:00:45 by cagirdem          #+#    #+#             */
/*   Updated: 2021/11/30 14:19:38 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_func(int i_array[], int size)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i <= size)
	{
		c = i + 1;
		while (c <= size)
		{
			if (i_array[i] > i_array[c])
			{
				ft_swap(&i_array[i], &i_array[c]);
			}
			c++;
		}
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	size = size - 1;
	sort_func(tab, size);
}
