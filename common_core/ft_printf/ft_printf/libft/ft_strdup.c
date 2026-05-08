/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:41:16 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/13 12:41:17 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		index;
	char	*res;

	len = 0;
	index = 0;
	while (s1[len])
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (res);
	while (*s1)
		res[index++] = *s1++;
	res[index] = '\0';
	return (res);
}
