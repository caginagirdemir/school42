/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:40:47 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/13 12:40:49 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			index;
	void			*result;
	unsigned char	*temp;

	index = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	temp = (unsigned char *)result;
	while (index < (count * size))
		temp[index++] = 0;
	return (result);
}
