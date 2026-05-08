/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:54:33 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/09 15:15:05 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	isInt(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	if(!str)
	{
		return (0);
	}
	while(ft_isdigit(str[i]))
	{
		result *=  10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}
/*
int main(void)
{
	printf("%d\n", ft_atoi("123"));
	return(0);
}*/
