/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:39:00 by cagirdem          #+#    #+#             */
/*   Updated: 2022/05/03 11:23:42 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <time.h>

typedef struct s_philo
{
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	long long		*last_eat;
	int				count;
	int				serving_count;
	int				eaten_count;
	int				*eaten;
	pthread_mutex_t	msg;
	pthread_mutex_t	rook;
	pthread_mutex_t	*forks;
	pthread_t		*thread_id;
	struct timeval	start;
}	t_philo;

typedef struct s_arg
{
	t_philo	*philos;
	int		rank;
}	t_arg;

void		ft_usleep(unsigned int n);
long		get_ts(void);
int			ft_strncmp(char *str_1, char *str_2, int n);
int			ft_strlen(char *s);
int			ft_atoi(char *str);
int			invalid_arguments(int argc, char **argv);
void		run_threads(t_philo *ph);
void		print(t_philo *philos, char *str, long long time, int rank);
void		*live(void *arg);
void		s_sleep(t_philo *p, long long ms);
long long	gettime(struct timeval *s);

#endif
