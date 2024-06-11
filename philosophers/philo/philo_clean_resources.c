#include "philosophers.h"

void	free_mutex(t_philo *philo)
{
	t_info	*info;
	t_mutex	*mutex;
	int	i;

	i = 0;
	info = philo[0].info;
	mutex = philo[0].mutex;
	while (i < info->num_of_philosophers)
	{
		pthread_mutex_destroy(&mutex->fork_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&mutex->print_mutex);
	free(mutex->fork_mutex);
}

void	free_philo(t_philo *philo)
{
	free(philo->thread);
	free(philo->info);
	free(philo);
}

void	free_all(t_philo *philo)
{
	free_mutex(philo);
	free_philo(philo);
}
