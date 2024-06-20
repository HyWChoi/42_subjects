/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:44 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:38:58 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	ph_finish_eat(t_philo *philo)
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
