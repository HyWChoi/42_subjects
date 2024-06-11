#include "philosophers.h"

int	ph_eat(t_philo *philo)
{
	t_info	*info;
	t_mutex	*mutex;

	info = philo->info;
	mutex = philo->mutex;
	// if (philo->id % 2 == 0)
	// {
	// pthread_mutex_lock(&mutex->fork_mutex[philo->left_fork]);
	// ph_print(philo, "has taken a fork");
	// pthread_mutex_lock(&mutex->fork_mutex[philo->right_fork]);
	// ph_print(philo, "has taken a fork");
	// }
	// else
	// {
	// pthread_mutex_lock(&mutex->fork_mutex[philo->right_fork]);
	// ph_print(philo, "has taken a fork");
	// pthread_mutex_lock(&mutex->fork_mutex[philo->left_fork]);
	// ph_print(philo, "has taken a fork");
	// }
	pthread_mutex_lock(&mutex->fork_mutex[philo->left_fork]);
	ph_print(philo, "has taken a fork");
	pthread_mutex_lock(&mutex->fork_mutex[philo->right_fork]);
	ph_print(philo, "has taken a fork");
	ph_print(philo, "is eating");
	philo->last_eat = ph_get_time();
	philo->eat_count++;
	ph_flow_time(info->time_to_eat);
	pthread_mutex_unlock(&mutex->fork_mutex[philo->right_fork]);
	pthread_mutex_unlock(&mutex->fork_mutex[philo->left_fork]);
	return (0);
}

int	ph_sleep(t_philo *philo)
{
	ph_print(philo, "is sleeping");
	philo->sleep_count++;
	ph_flow_time(philo->info->time_to_sleep);
	return (0);
}

int	ph_think(t_philo *philo)
{
	ph_print(philo, "is thinking");
	return (0);
}

int	ph_die(t_philo *philo)
{
	ph_print(philo, "died");
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
		if (info->time_to_must_eat != -1 && philo->eat_count >= info->time_to_must_eat)
			break ;
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (0);
}
