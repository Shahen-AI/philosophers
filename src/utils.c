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
	if(nptr[i] != '\0')
		return (-1);
	return (sum);
}

long long ft_time()
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
