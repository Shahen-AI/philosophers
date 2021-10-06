#include "../philo.h"

// int ft_strlen(char *str)
// {
// 	int len = 0;

// 	while (str[len])
// 		++len;
// 	return (len);
// }

// int ft_error(char *str)
// {
// 	write(1, str, ft_strlen(str));
// }

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

long long ft_time()
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);// - g_glob.tv.tv_sec * 1000 + g_glob.tv.tv_usec / 1000);
}
