#include "philo.h"

int parsing(int argc, char **argv)
{
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
	philo_init(argc, argv);
	return (0);
}

int philo_init(int argc, char **argv)
{
	g_glob.num = ft_atoi(argv[1]);
	g_glob.die = ft_atoi(argv[2]);
	g_glob.eat = ft_atoi(argv[3]);
	g_glob.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		g_glob.must_eat = ft_atoi(argv[5]);
	return (argc);
}

void *philo_start(void *nm)
{
	int i = *((int *)nm) + 1;

	printf("%d %d is thinking\n", ft_time(), i);
	pthread_mutex_lock(&g_mutex[i].fork);
	printf("%d %d has taken a fork\n", ft_time(), i);
	usleep(g_glob.eat);
	printf("%d %d is sleeping\n", ft_time(), i);
	usleep(g_glob.sleep);
	pthread_mutex_unlock(&g_mutex[i].fork);
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0, res;

	if (parsing(argc, argv))
		return (0);
	gettimeofday(&g_glob.tv, NULL);
	philo = malloc(sizeof(*philo) * g_glob.num);
	g_mutex = malloc(sizeof(*g_mutex) * g_glob.num);
	while (i < g_glob.num)
	{
		pthread_mutex_init(&g_mutex[i].fork, NULL);
		res = pthread_create(&philo[i].thr, NULL, philo_start, (void *)&i);
		if (res != 0)
			break ;
		++i;
	}
	// res = pthread_join(philo[1].thr, NULL);
	i = 0;
	while (i < g_glob.num)
	{
		pthread_mutex_destroy(&g_mutex[i].fork);
		++i;
	}
	i = 0;
	while (i < g_glob.num)
	{
		res = pthread_join(philo[i].thr, NULL);
		if (res != 0)
			break ;
		++i;
	}
	return (0);
}
