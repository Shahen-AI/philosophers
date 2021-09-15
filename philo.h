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
}		*g_mutex;

struct g_globs
{
	int num;
	int eat;
	int die;
	int sleep;
	int must_eat;
	struct timeval tv;
}		g_glob;

struct s_philo
{
	int cur_time;
	pthread_t thr;
}   *philo;

int ft_time();
int	ft_atoi(const char *nptr);
int philo_init(int argc, char **argv);
int parsing(int argc, char **argv);

#endif