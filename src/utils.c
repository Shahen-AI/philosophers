/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:54:36 by ster-min          #+#    #+#             */
/*   Updated: 2021/10/20 21:54:37 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	sum;

	i = 0;
	sum = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		++i;
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		sum = (sum * 10) + (nptr[i] - '0');
		++i;
	}
	if (nptr[i] != '\0')
		return (-1);
	return (sum);
}

long long	ft_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	custom_sleep(int time)
{
	struct timeval	start;
	long long		cur_time;

	gettimeofday(&start, NULL);
	cur_time = start.tv_sec * 1000 + start.tv_usec / 1000;
	while (ft_time() - cur_time < time)
		usleep(50);
}

void	print_event(char *str, int i)
{
	pthread_mutex_lock(&g_mutex[0].message);
	printf("%lld %d %s\n", ft_time() - g_glob.start, i, str);
	if (!g_glob.is_dead)
		pthread_mutex_unlock(&g_mutex[0].message);
}
