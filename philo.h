/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:54:50 by ster-min          #+#    #+#             */
/*   Updated: 2021/10/20 21:54:52 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <assert.h>

struct s_mutex
{
	pthread_mutex_t	fork;
	pthread_mutex_t	message;
}		*g_mutex;

struct				s_globs
{
	int				num;
	int				eat;
	int				die;
	int				sleep;
	int				must_eat;
	int				*phil_num;
	int				is_dead;
	int				must_eat_check;
	long long		start;
	struct timeval	tv;
}		g_glob;

struct s_philo
{
	int			eat_count;
	long long	last_eat;
	pthread_t	thr;
}	*philo;

void		philo_init(int argc, char **argv);
int			parsing(int argc, char **argv);

void		*philo_start(void *nm);
void		*eating(int i);
void		*philo_death(void *nm);

long long	ft_time(void);
int			ft_atoi(const char *nptr);
void		print_event(char *str, int i);
void		custom_sleep(int time);

#endif
