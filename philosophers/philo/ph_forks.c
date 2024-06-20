/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:50 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:37:50 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ph_put_donw_all_forks(t_philo *philo)
{
	ph_put_down_fork(philo, philo->right_fork);
	ph_put_down_fork(philo, philo->left_fork);
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

int	ph_try_fork(t_philo *philo, int fork_num)
{
	while (!ph_is_available_fork(philo, fork_num))
	{
		if (!ph_is_available_execute(philo))
			return (1);
		usleep(50);
	}
	if (!ph_is_available_execute(philo))
		return (1);
	ph_put_up_fork(philo, fork_num);
	return (0);
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
