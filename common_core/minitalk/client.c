/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:09:23 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/07 18:12:29 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		received++;
	else if (sig == SIGUSR2)
	{
		ft_putnbr(received);
		write (1, "\n", 1);
		exit(0);
	}
}

static void	pulse(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	write(1, "Sent :", 6);
	ft_putnbr(ft_strlen(argv[2]));
	write(1, "\n", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	pulse(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
