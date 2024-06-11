#include "philosophers.h"

int	ph_check_finish(t_philo *philo)
{
	int	i;
	t_info	*info;

	i = 0;
	info = philo[0].info;
	while (i < info->num_of_philosophers)
	{
		if (philo[i].eat_count < info->time_to_must_eat)
			break ;
		i++;
	}
	if (i == info->num_of_philosophers)
	{
		info->finish = 1;
		return (1);
	}
	return (0);
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
	i = 0;
	while (i < info->num_of_philosophers)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	// free_all(info, philo);
	return (0);
}
