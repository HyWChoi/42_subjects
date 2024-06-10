#include "philosophers.h"

int	ph_atoi(const char *str)
{
	int		i;
	int		sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return ((int)(nbr * sign));
}

long	ph_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ph_print(t_info *info, t_philo *philo, char *status)
{
	pthread_mutex_lock(&info->print_mutex);
	printf("%ld %d %s\n", ph_get_time() - info->start_time, philo->id, status);
	pthread_mutex_unlock(&info->print_mutex);
	return (0);
}

int	ph_flow_time(long long time)
{
	long long	start;
	long long	end;

	start = ph_get_time();
	while (1)
	{
		end = ph_get_time();
		if (end - start >= time)
			break ;
		usleep(100);
	}
	return (0);
}
