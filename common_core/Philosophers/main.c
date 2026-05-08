/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:39:29 by cagirdem          #+#    #+#             */
/*   Updated: 2022/05/03 11:22:58 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death_control(t_philo *ph)
{
	long long	time_passed;
	int			i;

	while (1)
	{
		i = -1;
		while (++i < ph->count)
		{
			pthread_mutex_lock(&ph->rook);
			time_passed = gettime(&ph->start) - ph->last_eat[i];
			if (time_passed >= ph->die_time)
			{
				pthread_mutex_lock(&ph->msg);
				time_passed = gettime(&ph->start);
				printf("%lld %d died\n", time_passed, i + 1);
				exit(0);
			}
			pthread_mutex_unlock(&ph->rook);
		}
	}
}

void	print(t_philo *philos, char *str, long long time, int rank)
{
	pthread_mutex_lock(&philos->msg);
	printf("%lld %d %s", time, rank, str);
	pthread_mutex_unlock(&philos->msg);
}

void	ph_init_2(t_philo *ph)
{
	int	i;

	i = -1;
	ph->eaten_count = ph->count;
	ph->forks = malloc(ph->count * sizeof(pthread_mutex_t));
	while (++i < ph->count)
		pthread_mutex_init(&ph->forks[i], NULL);
	pthread_mutex_init(&ph->msg, NULL);
	pthread_mutex_init(&ph->rook, NULL);
}

void	ph_init(t_philo *ph, char **argv, int argc)
{
	ph->thread_id = (pthread_t *)malloc(ph->count * sizeof(pthread_t *));
	ph->last_eat = (long long *)malloc(ph->count * sizeof(long long));
	ph->eaten = (int *)malloc(ph->count * sizeof(int));
	memset(ph->eaten, 0, ph->count * sizeof(int));
	memset(ph->last_eat, 0, ph->count * sizeof(int));
	ph->die_time = ft_atoi(argv[2]);
	ph->eat_time = ft_atoi(argv[3]);
	ph->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		ph->serving_count = ft_atoi(argv[5]);
	else
		ph->serving_count = 2147483647;
	ph_init_2(ph);
}

int	main(int argc, char **argv)
{
	t_philo	ph;

	if (argc != 6 && argc != 5)
		return (printf("Error: argument count\n"));
	if (invalid_arguments(argc, argv))
		return (printf("Error: invalid argument\n"));
	ph.count = ft_atoi(argv[1]);
	ph_init(&ph, argv, argc);
	run_threads(&ph);
	death_control(&ph);
	return (0);
}
