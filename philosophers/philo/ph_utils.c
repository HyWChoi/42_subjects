/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:38:28 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 16:57:17 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ph_vaild_info(t_info *info, int argc)
{
	if (info->num_of_philosophers < 1)
		return (FALSE);
	if (info->time_to_die < 0)
		return (FALSE);
	if (info->time_to_eat < 0)
		return (FALSE);
	if (info->time_to_sleep < 0)
		return (FALSE);
	if (argc == 6 && info->time_to_must_eat < 0)
		return (FALSE);
	return (TRUE);
}

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
	int		i;
	t_mutex	*mutex;

	i = 0;
	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->finish_mutex);
	mutex->finish = TRUE;
	pthread_mutex_unlock(&mutex->finish_mutex);
	return (0);
}

long	ph_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
