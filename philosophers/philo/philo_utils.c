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
	if (str[i] == '+')
		i++;
	if (str[i] > '9' && str[i] < '0')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] > '9' && str[i] < '0')
		return (-1);
	return ((int)(nbr * sign));
}

long	ph_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ph_print(t_philo *philo, char *status)
{
	t_info	*info;
	t_mutex	*mutex;

	info = philo->info;
	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->print_mutex);
	printf("%ld %d %s\n", ph_get_time() - info->start_time, philo->id, status);
	pthread_mutex_unlock(&mutex->print_mutex);
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

t_info	*ph_copy_info(t_info *info)
{
	t_info	*new_info;

	new_info = (t_info *)malloc(sizeof(t_info));
	if (!new_info)
		return (NULL);
	new_info->num_of_philosophers = info->num_of_philosophers;
	new_info->time_to_die = info->time_to_die;
	new_info->time_to_eat = info->time_to_eat;
	new_info->time_to_sleep = info->time_to_sleep;
	new_info->time_to_must_eat = info->time_to_must_eat;
	new_info->start_time = info->start_time;
	new_info->finish = info->finish;
	return (new_info);
}
