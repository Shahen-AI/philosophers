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

int ft_time()
{
	struct timeval t2;
    int elapsedTime;

    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - g_glob.tv.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - g_glob.tv.tv_usec) / 1000.0;
	return (elapsedTime);
}
