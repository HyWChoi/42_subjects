#include "philosophers.h"

int		ph_finish_eat(t_philo *philo)
{
	t_mutex	*mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->finish_eat_mutex[philo->id - 1]);
	mutex->finish_eat[philo->id - 1] = TRUE;
	pthread_mutex_unlock(&mutex->finish_eat_mutex[philo->id - 1]);
	return (0);
}

t_bool	ph_is_finish_eat(t_philo *philo)
{
	if (philo->info->time_to_must_eat == -1)
		return (FALSE);
	if (philo->eat_count >= philo->info->time_to_must_eat)
		return (TRUE);
	return (FALSE);
}

t_bool	ph_is_dead(t_philo *philo)
{
	if ((ph_get_time() - philo->last_eat) >= philo->info->time_to_die)
	{
		ph_die(philo);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ph_is_available_execute(t_philo *philo)
{
	if (ph_check_finish(philo) || ph_is_dead(philo))
		return (FALSE);
	return (TRUE);
}

t_bool	ph_is_available_fork(t_philo *philo, int fork_num)
{
	t_mutex	*mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->fork_mutex[fork_num]);
	if (mutex->fork[fork_num] == TRUE)
	{
		pthread_mutex_unlock(&mutex->fork_mutex[fork_num]);
		return (TRUE);
	}
	pthread_mutex_unlock(&mutex->fork_mutex[fork_num]);
	return (FALSE);
}

void	ph_put_donw_all_forks(t_philo *philo)
{
	ph_put_down_fork(philo, philo->right_fork);
	ph_put_down_fork(philo, philo->left_fork);
}

int	ph_try_fork(t_philo *philo, int fork_num)
{
	while (!ph_is_available_fork(philo, fork_num))
	{
		if (!ph_is_available_execute(philo))
			return (1);
		usleep(300);
	}
	if (!ph_is_available_execute(philo))
		return (1);
	ph_put_up_fork(philo, fork_num);
	return (0);
}

int	ph_eat(t_philo *philo)
{
	t_info	*info;
	t_mutex	*mutex;

	info = philo->info;
	mutex = philo->mutex;
	if (ph_try_fork(philo, philo->left_fork))
		return (1);
	if (ph_try_fork(philo, philo->right_fork))
		return (1);
	ph_print(philo, "is eating");
	philo->eat_count++;
	philo->last_eat = ph_get_time();
	ph_flow_time(info->time_to_eat);
	ph_put_donw_all_forks(philo);
	if (ph_is_finish_eat(philo))
	{
		ph_finish_eat(philo);
		return (1);
	}
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

int	ph_is_lock_print(t_philo *philo)
{
	t_mutex *mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->print_lock_flag_mutex);
	if (mutex->print_lock_flag == TRUE)
	{
		pthread_mutex_unlock(&mutex->print_lock_flag_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&mutex->print_lock_flag_mutex);
	return (FALSE);
}

int	ph_lock_print(t_philo *philo)
{
	t_mutex *mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->print_lock_flag_mutex);
	mutex->print_lock_flag = TRUE;
	pthread_mutex_unlock(&mutex->print_lock_flag_mutex);
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
	pthread_mutex_unlock(&mutex->fork_mutex[fork_num]);
	return (0);
}

int	ph_put_down_fork(t_philo *philo, int fork_num)
{
	t_mutex	*mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->fork_mutex[fork_num]);
	mutex->fork[fork_num] = TRUE;
	pthread_mutex_unlock(&mutex->fork_mutex[fork_num]);
	return (0);
}

t_bool	check_and_do(t_philo *philo, int (*func)(t_philo *philo))
{
	if (!ph_is_available_execute(philo))
		return (FALSE);
	if (func(philo))
		return (FALSE);
	return (TRUE);
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
		if (!check_and_do(philo, ph_eat))
			break ;
		if (!check_and_do(philo, ph_sleep))
			break ;
		if (!check_and_do(philo, ph_think))
			break ;
	}
	return (0);
}
