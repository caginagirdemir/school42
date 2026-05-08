/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:34:24 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/13 12:34:26 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	index;
	size_t	t_size;

	d_len = 0;
	index = 0;
	while (dst[d_len])
		d_len++;
	if (dstsize <= d_len)
		return (dstsize + ft_strlen(src));
	t_size = d_len + ft_strlen(src);
	while (src[index] && d_len < dstsize - 1)
		dst[d_len++] = src[index++];
	dst[d_len] = '\0';
	return (t_size);
}
