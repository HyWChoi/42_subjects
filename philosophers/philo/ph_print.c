/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:38:04 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:40:50 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ph_is_lock_print(t_philo *philo)
{
	t_mutex	*mutex;

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
	t_mutex	*mutex;

	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->print_lock_flag_mutex);
	mutex->print_lock_flag = TRUE;
	pthread_mutex_unlock(&mutex->print_lock_flag_mutex);
	return (0);
}

int	ph_print_die(t_philo *philo)
{
	t_info	*info;
	t_mutex	*mutex;

	info = philo->info;
	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->print_mutex);
	if (ph_is_lock_print(philo))
	{
		pthread_mutex_unlock(&mutex->print_mutex);
		return (1);
	}
	ph_lock_print(philo);
	printf("%ld %d died\n", ph_get_time() - info->start_time, philo->id);
	pthread_mutex_unlock(&mutex->print_mutex);
	return (0);
}

int	ph_print(t_philo *philo, char *status)
{
	t_info	*info;
	t_mutex	*mutex;

	info = philo->info;
	mutex = philo->mutex;
	pthread_mutex_lock(&mutex->print_mutex);
	if (ph_is_lock_print(philo))
	{
		pthread_mutex_unlock(&mutex->print_mutex);
		return (1);
	}
	printf("%ld %d %s\n", ph_get_time() - info->start_time, philo->id, status);
	pthread_mutex_unlock(&mutex->print_mutex);
	return (0);
}

int	ph_print_err(char *str, int ret)
{
	printf("%s\n", str);
	return (ret);
}
