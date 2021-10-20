/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:54:16 by ster-min          #+#    #+#             */
/*   Updated: 2021/10/20 21:54:18 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*eating(int i)
{
	if (i == g_glob.num)
		pthread_mutex_lock(&g_mutex[0].fork);
	else
		pthread_mutex_lock(&g_mutex[i].fork);
	print_event("has taken a fork", i);
	pthread_mutex_lock(&g_mutex[i - 1].fork);
	print_event("has taken a fork", i);
	print_event("is eating", i);
	philo[i - 1].last_eat = ft_time() - g_glob.start;
	custom_sleep(g_glob.eat);
	if (i == g_glob.num)
		pthread_mutex_unlock(&g_mutex[0].fork);
	else
		pthread_mutex_unlock(&g_mutex[i].fork);
	pthread_mutex_unlock(&g_mutex[i - 1].fork);
	print_event("is sleeping", i);
	custom_sleep(g_glob.sleep);
	return (0);
}

void	*philo_death(void *nm)
{
	int	i;

	i = *((int *)nm);
	while (1)
	{
		if (ft_time() - philo[i - 1].last_eat - g_glob.start > g_glob.die)
		{
			g_glob.is_dead = 1;
			print_event("is dead", i);
			return (0);
		}
	}
}

void	*philo_start(void *nm)
{
	int			i;
	pthread_t	death;

	i = *((int *)nm) + 1;
	pthread_create(&death, NULL, philo_death, (void *)&i);
	if (i % 2 == 0)
		usleep(1000);
	while (!g_glob.is_dead)
	{
		print_event("is thinking", i);
		eating(i);
		++philo[i - 1].eat_count;
		if (g_glob.must_eat == philo[i - 1].eat_count)
			++g_glob.must_eat_check;
		if (g_glob.must_eat_check == g_glob.num)
			g_glob.is_dead = 1;
	}
	return (0);
}
