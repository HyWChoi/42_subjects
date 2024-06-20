/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:25 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:37:25 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ph_destroy_mutex_array(pthread_mutex_t *mutex, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&mutex[i]);
		i--;
	}
}

void	ph_free_mutex(t_mutex *mutex)
{
	free(mutex->fork_mutex);
	free(mutex->death_mutex);
	free(mutex->finish_eat_mutex);
	free(mutex->fork);
	free(mutex->death);
	free(mutex->finish_eat);
	free(mutex);
}

void	ph_clean_mutex(t_mutex *mutex, int num_of_philosophers)
{
	ph_destroy_mutex(mutex, num_of_philosophers);
	ph_free_mutex(mutex);
}

void	ph_clean_philo(t_philo *philo, int num_of_philosophers)
{
	int	i;

	i = 0;
	while (i < num_of_philosophers)
	{
		free(philo[i].info);
		i++;
	}
	free(philo);
}

void	ph_clean_resources(t_info *info, t_mutex *mutex, t_philo *philo)
{
	ph_clean_mutex(mutex, info->num_of_philosophers);
	ph_clean_philo(philo, info->num_of_philosophers);
	free(info);
}
