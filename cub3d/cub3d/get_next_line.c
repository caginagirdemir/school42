/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:19:54 by cagirdem          #+#    #+#             */
/*   Updated: 2022/06/12 12:20:20 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*myfree(void *f)
{
	free(f);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*ret;
	char	buff;
	int		i;
	int		j;

	buff = 0;
	i = 0;
	j = 0;
	ret = (char *)malloc(9999);
	while (1)
	{
		i = read(fd, &buff, 1);
		if (i <= 0)
			break ;
		ret[j++] = buff;
		if (buff == '\n')
			break ;
	}
	ret[j] = 0;
	if (!*ret)
		return (myfree(ret));
	return (ret);
}
