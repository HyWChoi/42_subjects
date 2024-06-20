/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:38:26 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:41:08 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	ph_thread_create(t_philo *philo)
{
	int		i;
	t_info	*info;

	i = 0;
	info = philo[0].info;
	while (i < info->num_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, ph_do, (void *)&philo[i]))
		{
			while (i >= 0)
			{
				pthread_detach(philo[i].thread);
				i--;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	ph_thread_join(t_philo *philo)
{
	int		i;
	t_info	*info;

	i = 0;
	info = philo[0].info;
	while (i < info->num_of_philosophers)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int	ph_philo_start(t_philo *philo)
{
	if (ph_thread_create(philo))
		return (1);
	ph_watcher(philo);
	ph_thread_join(philo);
	return (0);
}
