#include "philosophers.h"

int	ph_init_mutex_info(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->print_mutex, NULL))
		return (1);
	info->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->num_of_philosophers);
	if (!info->fork_mutex)
		return (1);
	i = 0;
	while (i < info->num_of_philosophers)
	{
		if (pthread_mutex_init(&info->fork_mutex[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&info->finish_mutex, NULL))
		return (1);
	return (0);
}

t_info	*ph_init_info(int argc, char *argv[])
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->num_of_philosophers = ph_atoi(argv[1]);
	info->time_to_die = ph_atoi(argv[2]);
	info->time_to_eat = ph_atoi(argv[3]);
	info->time_to_sleep = ph_atoi(argv[4]);
	info->finish = 0;
	if (argc == 6)
		info->time_to_must_eat = ph_atoi(argv[5]);
	else
		info->time_to_must_eat = -1;
	info->start_time = ph_get_time();
	if (ph_init_mutex_info(info))
	{
		free(info);
		return (NULL);
	}
	return (info);
}

t_philo	*ph_init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philosophers);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < info->num_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].death = 0;
		philo[i].eat_count = 0;
		philo[i].sleep_count = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % info->num_of_philosophers;
		philo[i].last_eat = 0;
		philo[i].info = info;
		philo[i].start = (void *)philo;
		pthread_mutex_init(&philo[i].eating_mutex, NULL);
		i++;
	}
	return (philo);
}
