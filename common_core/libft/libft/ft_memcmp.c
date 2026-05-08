/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:39:02 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/13 12:39:03 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_t;
	const unsigned char	*s2_t;

	if (!n)
		return (0);
	s1_t = (const unsigned char *)s1;
	s2_t = (const unsigned char *)s2;
	while (*s1_t++ == *s2_t++ && n - 1)
		n--;
	return (*--s1_t - *--s2_t);
}
