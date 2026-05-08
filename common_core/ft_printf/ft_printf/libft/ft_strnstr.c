/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:39:28 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/13 12:39:30 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	jndex;

	jndex = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && jndex < len)
	{
		index = 0;
		while (needle[index] && haystack[index] == needle[index]
			&& ((jndex + index) < len))
			index++;
		if (!needle[index])
			return ((char *)haystack);
		jndex++;
		haystack++;
	}
	return (0);
}
