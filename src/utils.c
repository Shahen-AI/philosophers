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
