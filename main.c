#include "philo.h"

int parsing(int argc, char **argv)
{
	// gettimeofday(&g_glob.tv, NULL);
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
	philo_init(argc, argv);
	return (0);
}

void philo_init(int argc, char **argv)
{
	int i = 0;
	g_glob.num = ft_atoi(argv[1]);
	g_glob.die = ft_atoi(argv[2]);
	g_glob.eat = ft_atoi(argv[3]);
	g_glob.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		g_glob.must_eat = ft_atoi(argv[5]);
	g_glob.philNum = malloc(sizeof(int) * g_glob.num);
	g_glob.philDeath = malloc(sizeof(int) * g_glob.num);
	philo = malloc(sizeof(pthread_t) * g_glob.num);
	g_mutex = malloc(sizeof(pthread_mutex_t) * g_glob.num);
	while (i < g_glob.num)
	{
		g_glob.philNum[i] = i;
		g_glob.philDeath[i] = i;
		philo[i].last_eat = 0;
		++i;
	}
	g_glob.is_dead = 0;
}

void print_event(char *str, int i)
{
	pthread_mutex_lock(&g_mutex[0].message);
	printf("%lld %d %s\n", ft_time() - g_glob.start, i, str);
	if (!g_glob.is_dead)
		pthread_mutex_unlock(&g_mutex[0].message);
}

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
	if (g_glob.is_dead)
		return (0);
	philo[i].last_eat = ft_time() - g_glob.start;
	usleep(g_glob.eat * 1000);
	if (g_glob.is_dead)
		return (0);
	if (i == g_glob.num)
		pthread_mutex_unlock(&g_mutex[0].fork);
	else
		pthread_mutex_unlock(&g_mutex[i].fork);
	pthread_mutex_unlock(&g_mutex[i - 1].fork);
	print_event("is sleeping", i);
	usleep(g_glob.sleep * 1000);
	return (0);
}

void	*philo_death(void *nm)
{
	int i = *((int *)nm);

	while (1)
	{
		if (ft_time() - philo[i].last_eat - g_glob.start > g_glob.die)
		{
			g_glob.is_dead = 1;
			print_event("is dead", i);
			return (0);
		}
	}
}

void *philo_start(void *nm)
{
	int	i;
	int	res;
	pthread_t	death;

	i = *((int *)nm) + 1;
	res = pthread_create(&death, NULL, philo_death, (void *)&i);
	if (res != 0)
		return (0);
	if (i % 2 == 0)
		usleep(1000);
	while (!g_glob.is_dead)
	{
		print_event("is thinking", i);
		eating(i);
		// if (g_glob.is_dead)
		// 	break ;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0, res;

	if (parsing(argc, argv))
		return (0);
	
	pthread_mutex_init(&g_mutex[0].message, NULL);
	while (i < g_glob.num)
	{
		pthread_mutex_init(&g_mutex[i].fork, NULL);
		res = pthread_create(&philo[i].thr, NULL, philo_start, (void *)&g_glob.philNum[i]);
		if (res != 0)
			break ;
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
	i = 0;
	pthread_mutex_destroy(&g_mutex[0].message);
	while (i < g_glob.num)
	{
		pthread_mutex_destroy(&g_mutex[i].fork);
		++i;
	}
	return (0);
}
