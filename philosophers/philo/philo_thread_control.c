#include "philosophers.h"

int	ph_check_finish(t_philo *philo)
{
	int		i;
	t_info	*info;
	t_mutex	*mutex;

	i = 0;
	mutex = philo[0].mutex;
	info = philo[0].info;
	while (i < info->num_of_philosophers)
	{
		pthread_mutex_lock(&mutex->death_mutex[i]);
		if (mutex->death[i] == FALSE)
		{
			pthread_mutex_unlock(&mutex->death_mutex[i]);
			return (FALSE);
		}
		if (ph_get_time() - philo[i].last_eat >= info->time_to_die)
		{
			printf("is here>? %d\n", i);
			ph_die(&philo[i]);
			printf("is here>2? %d\n", i);
			pthread_mutex_unlock(&mutex->death_mutex[i]);
			pthread_mutex_lock(&mutex->finish_mutex);
			mutex->finish = TRUE;
			pthread_mutex_unlock(&mutex->finish_mutex);
			return (TRUE);
		}
		pthread_mutex_unlock(&mutex->death_mutex[i]);
		i++;
	}
	return (FALSE);
}

int	ph_philo_start(t_philo *philo)
{
	int	i;
	t_info	*info;

	i = 0;
	info = philo[0].info;
	while (i < info->num_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, ph_do, (void *)&philo[i]))
			return (1);
		i++;
	}
	while (1)
	{
		if (ph_check_finish(philo))
			break ;
		usleep(60);
	}
	i = 0;
	while (i < info->num_of_philosophers)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	// free_all(info, philo);
	return (0);
}
