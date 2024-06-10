#include "philosophers.h"

void	free_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philosophers)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print_mutex);
	free(info->fork_mutex);
}

void	free_philo(t_philo *philo)
{
	free(philo);
}

void	free_info(t_info *info)
{
	free_mutex(info);
	free(info->fork_mutex);
	free(info);
}

void	free_all(t_info *info, t_philo *philo)
{
	free_mutex(info);
	free_philo(philo);
	free_info(info);
}
