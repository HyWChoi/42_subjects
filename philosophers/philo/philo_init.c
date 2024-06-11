#include "philosophers.h"

t_mutex	*ph_init_mutex_info(int num_of_philosophers)
{
	t_mutex	*mutex;
	int	i;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (pthread_mutex_init(&mutex->print_mutex, NULL))
		return (NULL);
	mutex->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_of_philosophers);
	if (!mutex->fork_mutex)
		return (NULL);
	i = 0;
	while (i < num_of_philosophers)
	{
		if (pthread_mutex_init(&mutex->fork_mutex[i], NULL))
			return (NULL);
		i++;
	}
	return (mutex);
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
	return (info);
}

t_philo	*ph_init_philo(t_info *info, t_mutex *mutex)
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
		philo[i].info = ph_copy_info(info);
		philo[i].mutex = mutex;
		i++;
	}
	return (philo);
}
