#include "philosophers.h"

int	ph_eat(t_philo *philo)
{
	t_info	*info;
	t_mutex	*mutex;

	info = philo->info;
	mutex = philo->mutex;
	ph_put_up_fork(philo, philo->left_fork);
	ph_put_up_fork(philo, philo->right_fork);
	ph_print(philo, "is eating");
	philo->eat_count++;
	philo->last_eat = ph_get_time();
	ph_flow_time(info->time_to_eat);
	ph_put_down_fork(philo, philo->right_fork);
	ph_put_down_fork(philo, philo->left_fork);
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
	t_mutex	*mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->death_mutex[philo->id - 1]);
	mutex->death[philo->id - 1] = TRUE;
	ph_print(philo, "died");
	pthread_mutex_unlock(&mutex->death_mutex[philo->id - 1]);
	return (0);
}

int	ph_put_up_fork(t_philo *philo, int fork_num)
{
	t_mutex	*mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->fork_mutex[fork_num]);
	ph_print(philo, "has taken a fork");
	mutex->fork[fork_num] = FALSE;
	return (0);
}

int	ph_put_down_fork(t_philo *philo, int fork_num)
{
	t_mutex	*mutex;

	mutex = philo->mutex;
	mutex->fork[fork_num] = TRUE;
	pthread_mutex_unlock(&mutex->fork_mutex[fork_num]);
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
		if ((ph_get_time() - philo->last_eat) >= info->time_to_die)
		{
			ph_die(philo);
			break ;
		}
		if (info->time_to_must_eat != -1 && philo->eat_count >= info->time_to_must_eat)
			break ;
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (0);
}
