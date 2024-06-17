#include "philosophers.h"

t_bool	ph_is_exist_die(t_philo *philo)
{
	int		philo_id;
	t_mutex	*mutex;
	t_info	*info;

	philo_id = 0;
	mutex = philo->mutex;
	info = philo->info;
	while (philo_id < info->num_of_philosophers)
	{
		pthread_mutex_lock(&mutex->death_mutex[philo_id]);
		if (mutex->death[philo_id] == TRUE)
		{
			pthread_mutex_unlock(&mutex->death_mutex[philo_id]);
			return (TRUE);
		}
		pthread_mutex_unlock(&mutex->death_mutex[philo_id]);
		philo_id++;
	}
	return (FALSE);
}

int	ph_check_finish(t_philo *philo)
{
	t_mutex	*mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->finish_mutex);
	if (mutex->finish == TRUE)
	{
		pthread_mutex_unlock(&mutex->finish_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&mutex->finish_mutex);
	return (FALSE);
}

int	ph_force_quit(t_philo *philo)
{
	int	i;
	t_mutex	*mutex;

	i = 0;
	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->finish_mutex);
	mutex->finish = TRUE;
	pthread_mutex_unlock(&mutex->finish_mutex);
	return (0);
}

t_bool	ph_check_done_eating(t_philo *philo)
{
	int		i;
	t_info	*info;
	t_mutex	*mutex;

	i = 0;
	info = philo->info;
	mutex = philo->mutex;
	if (info->time_to_must_eat == -1)
		return (FALSE);
	while (i < info->num_of_philosophers)
	{
		pthread_mutex_lock(&mutex->finish_eat_mutex[i]);
		if (!mutex->finish_eat[i])
		{
			pthread_mutex_unlock(&mutex->finish_eat_mutex[i]);
			return (FALSE);
		}
		pthread_mutex_unlock(&mutex->finish_eat_mutex[i]);
		i++;
	}
	return (TRUE);
}

int	ph_thread_create(t_philo *philo)
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
	return (0);
}

void	ph_watcher(t_philo *philo)
{
	while (1)
	{
		if (ph_is_exist_die(philo) || ph_check_done_eating(philo))
		{
			ph_force_quit(philo);
			break ;
		}
		usleep(50);
	}
}

void	ph_thread_join(t_philo *philo)
{
	int	i;
	t_info	*info;

	i = 0;
	info = philo[0].info;
	while (i < info->num_of_philosophers)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int	ph_philo_start(t_philo *philo)
{
	if (ph_thread_create(philo))
		return (1);
	ph_watcher(philo);
	ph_thread_join(philo);
	return (0);
}
