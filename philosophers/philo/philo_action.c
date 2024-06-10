#include "philosophers.h"

int	ph_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->fork_mutex[philo->left_fork]);
	ph_print(info, philo, "has taken a fork");
	pthread_mutex_lock(&info->fork_mutex[philo->right_fork]);
	ph_print(info, philo, "has taken a fork");
	ph_print(info, philo, "is eating");
	philo->last_eat = ph_get_time();
	pthread_mutex_lock(&philo->eating_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eating_mutex);
	ph_flow_time(info->time_to_eat);
	pthread_mutex_unlock(&info->fork_mutex[philo->right_fork]);
	pthread_mutex_unlock(&info->fork_mutex[philo->left_fork]);
	return (0);
}

int	ph_sleep(t_info *info, t_philo *philo)
{
	ph_print(info, philo, "is sleeping");
	philo->sleep_count++;
	ph_flow_time(info->time_to_sleep);
	return (0);
}

int	ph_think(t_info *info, t_philo *philo)
{
	ph_print(info, philo, "is thinking");
	return (0);
}

int	ph_die(t_info *info, t_philo *philo)
{
	ph_print(info, philo, "died");
	philo->death = 1;
	return (0);
}

void	*ph_do(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 1)
		ph_flow_time(100);
	while (1)
	{
		// if (philo->eat_count != info->time_to_must_eat)
		if (info->time_to_must_eat != -1)
			ph_check_finish(info, (t_philo *)philo->start);
		pthread_mutex_lock(&info->finish_mutex);
		if (info->finish)
		{
			pthread_mutex_unlock(&info->finish_mutex);
			break ;
		}
		pthread_mutex_unlock(&info->finish_mutex);
		ph_eat(info, philo);
		ph_sleep(info, philo);
		ph_think(info, philo);
	}
	return (0);
}

int	ph_check_finish(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_of_philosophers)
	{
		// printf("philo[%d].eat_count = %d\n", i, philo[i].eat_count);
		// printf("info->time_to_must_eat = %d\n", info->time_to_must_eat);
		pthread_mutex_lock(&philo[i].eating_mutex);
		if (philo[i].eat_count < info->time_to_must_eat)
		{
			pthread_mutex_unlock(&philo[i].eating_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo[i].eating_mutex);
		i++;
	}
	pthread_mutex_lock(&info->finish_mutex);
	if (i == info->num_of_philosophers)
	{
		info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&info->finish_mutex);
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
