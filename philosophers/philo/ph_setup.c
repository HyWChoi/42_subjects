/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:38:24 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:40:58 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ph_set_mutexed_value(t_mutex *mutex, int num_of_philosophers)
{
	int	i;

	i = 0;
	while (i < num_of_philosophers)
	{
		mutex->fork[i] = TRUE;
		mutex->death[i] = FALSE;
		mutex->finish_eat[i] = FALSE;
		i++;
	}
	mutex->print_lock_flag = FALSE;
	mutex->finish = FALSE;
}

void	*ph_set_start(t_info *info, t_mutex **mutex, t_philo **philo)
{
	*mutex = ph_make_mutex(info->num_of_philosophers);
	if (!mutex)
		return (NULL);
	*philo = ph_init_philo(info, *mutex);
	if (!philo)
	{
		ph_clean_mutex(*mutex, info->num_of_philosophers);
		return (NULL);
	}
	return (philo);
}

t_info	*ph_set_info(t_info **info, int argc, char *argv[])
{
	(*info) = ph_init_info(argc, argv);
	if (!*info)
		return (NULL);
	if (!ph_vaild_info(*info, argc))
	{
		free(*info);
		return (NULL);
	}
	return (*info);
}
