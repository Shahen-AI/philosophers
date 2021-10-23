/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:53:47 by ster-min          #+#    #+#             */
/*   Updated: 2021/10/20 21:53:50 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_global(void *nm)
{
	while (!g_glob.is_dead)
	{
		usleep(50);
	}
	return (nm);
}

int	main(int argc, char **argv)
{
	int			i;
	pthread_t	glob;

	i = -1;
	if (parsing(argc, argv))
		return (1);
	pthread_mutex_init(&g_mutex[0].message, NULL);
	pthread_create(&glob, NULL, ft_global, NULL);
	while (++i < g_glob.num)
	{
		pthread_mutex_init(&g_mutex[i].fork, NULL);
		pthread_create(&philo[i].thr, NULL,
			philo_start, (void *)&g_glob.phil_num[i]);
	}
	pthread_join(glob, NULL);
	free(g_glob.phil_num);
	free(philo);
	free(g_mutex);
	return (0);
}
