/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:33:41 by cagirdem          #+#    #+#             */
/*   Updated: 2021/12/04 12:43:05 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	space_flag;

	i = 0;
	space_flag = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (space_flag == 1)
			{
				str[i] -= 32;
			}
			space_flag = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			space_flag = 0;
		else
			space_flag = 1;
		i++;
	}
	return (str);
}
