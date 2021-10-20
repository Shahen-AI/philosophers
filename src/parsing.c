/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:54:26 by ster-min          #+#    #+#             */
/*   Updated: 2021/10/20 21:54:28 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	parsing(int argc, char **argv)
{
	g_glob.start = ft_time();
	if (argc != 5 && argc != 6)
	{
		printf("Argument Error.\n");
		printf("Usage : ./philo ");
		printf("[number_of_philosophers] ");
		printf("[time_to_die] ");
		printf("[time_to_eat] ");
		printf("[time_to_sleep] ");
		printf("if necessary : [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == -1 || ft_atoi(argv[2]) == -1
		|| ft_atoi(argv[3]) == -1 || ft_atoi(argv[4]) == -1
		|| (argc == 6 && ft_atoi(argv[5]) == -1))
	{
		printf("ERROR\n");
		return (1);
	}
	philo_init(argc, argv);
	return (0);
}

void	philo_init(int argc, char **argv)
{
	int	i;

	i = 0;
	g_glob.num = ft_atoi(argv[1]);
	g_glob.die = ft_atoi(argv[2]);
	g_glob.eat = ft_atoi(argv[3]);
	g_glob.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		g_glob.must_eat = ft_atoi(argv[5]);
	else
		g_glob.must_eat = -1;
	g_glob.phil_num = malloc(sizeof(int) * g_glob.num);
	philo = malloc(sizeof(*philo) * g_glob.num);
	g_mutex = malloc(sizeof(pthread_mutex_t) * g_glob.num);
	while (i < g_glob.num)
	{
		g_glob.phil_num[i] = i;
		philo[i].last_eat = 0;
		philo[i].eat_count = 0;
		++i;
	}
	g_glob.is_dead = 0;
	g_glob.must_eat_check = 0;
}
