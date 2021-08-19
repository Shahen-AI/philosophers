#include "philo.h"

int philo_init(int argc, char **argv, t_philo *philo)
{
	philo->num = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->must_eat = ft_atoi(argv[5]);
	return (argc);
}

void *perform_work(void *arguments, t_philo *philo)
{
	int index = *((int *)arguments);
	int sleep_time = 1 + rand() % philo->num;
	printf("THREAD %d: Started.\n", index);
	printf("THREAD %d: Will be sleeping for %d seconds.\n", index, sleep_time);
	sleep(sleep_time);
	printf("THREAD %d: Ended.\n", index);
	return (arguments);
}

int main(int argc, char **argv)
{
	t_philo philo;

	if (argc != 5 && argc != 6)
		return (0);
	philo_init(argc, argv, &philo);

	struct timeval tv;
	pthread_t philo[philo.num];
	int i = 0, res, thread_args[philo.num];;

	gettimeofday(&tv, NULL);
	while (i < philo.num)
	{
		printf("IN MAIN: Creating thread %d.\n", i);
		thread_args[i] = i;
		res = pthread_create(&philo[i], NULL, perform_work, &thread_args[i]);
		if (res != 0)
			break ;
		++i;
	}
	return (0);
}
