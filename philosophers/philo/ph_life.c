/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:56 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:37:57 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ph_is_dead(t_philo *philo)
{
	if ((ph_get_time() - philo->last_eat) >= philo->info->time_to_die)
	{
		ph_die(philo);
		return (TRUE);
	}
	return (FALSE);
}

int	ph_die(t_philo *philo)
{
	t_mutex	*mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->death_mutex[philo->id - 1]);
	mutex->death[philo->id - 1] = TRUE;
	ph_print_die(philo);
	pthread_mutex_unlock(&mutex->death_mutex[philo->id - 1]);
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

void	ph_watcher(t_philo *philo)
{
	while (1)
	{
		if (ph_is_exist_die(philo) || ph_check_done_eating(philo))
		{
			ph_force_quit(philo);
			break ;
		}
		usleep(50);
	}
}
