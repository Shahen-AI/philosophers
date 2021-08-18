#include "philo.h"

int main(int argc, char **argv)
{
	struct timeval tv;
	pthread_t philo[ft_atoi(argv[1])];

	if (argc != 5 && argc != 6)
		return (0);
	gettimeofday(&tv, NULL);
	double time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	printf("old - %f\n", time_in_mill);
	usleep(1000000);
	gettimeofday(&tv, NULL);
	time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 - time_in_mill;
	printf("difference - %f\n", time_in_mill);
	// pthread_create();
	return (0);
}
