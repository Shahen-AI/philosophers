#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <assert.h>

struct s_mutex
{
	pthread_mutex_t fork;
	pthread_mutex_t message;
}		*g_mutex;

struct g_globs
{
	int num;
	int eat;
	int die;
	int sleep;
	int must_eat;
	int *philNum;
	int is_dead;
	long long start;
	struct timeval tv;
}		g_glob;

struct s_philo
{
	int eat_count;
	long long last_eat;
	pthread_t thr;
}   *philo;

long long ft_time();
int	ft_atoi(const char *nptr);
void philo_init(int argc, char **argv);
int parsing(int argc, char **argv);

#endif