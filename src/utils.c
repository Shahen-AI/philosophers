#include "../philo.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		positive;
	long	sum;

	i = 0;
	sum = 0;
	positive = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		++i;
	if (nptr[i] == '+')
		++i;
	else if (nptr[i] == '-')
	{
		positive *= -1;
		++i;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		sum = (sum * 10) + (nptr[i] - '0');
		++i;
	}
	return (positive * sum);
}

int ft_time(struct timeval tv1)
{
	struct timeval tv2;
	sleep(1);
	gettimeofday(&tv2, NULL);

	printf ("%f some shit to do\n",
         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec));
}
