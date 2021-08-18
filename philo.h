#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <assert.h>

typedef struct s_philo
{
    int num;
    int eat;
    int die;
    int sleep;
    int must_eat;

}   t_philo;

#endif