/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:54 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:37:55 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ph_init_array_mutex(t_mutex	*mutex, int num_of_philosophers)
{
	int	i;

	i = 0;
	while (i < num_of_philosophers)
	{
		if (pthread_mutex_init(&mutex->fork_mutex[i], NULL))
			return (FALSE);
		if (pthread_mutex_init(&mutex->death_mutex[i], NULL))
		{
			ph_destroy_mutex_array(mutex->fork_mutex, i - 1);
			return (FALSE);
		}
		if (pthread_mutex_init(&mutex->finish_eat_mutex[i], NULL))
		{
			ph_destroy_mutex_array(mutex->fork_mutex, i - 1);
			ph_destroy_mutex_array(mutex->death_mutex, i - 1);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	*ph_mutex_init(t_mutex **mutex, int num_of_philosophers)
{
	if (pthread_mutex_init(&(*mutex)->print_mutex, NULL))
		return (NULL);
	if (pthread_mutex_init(&(*mutex)->finish_mutex, NULL))
	{
		pthread_mutex_destroy(&(*mutex)->print_mutex);
		return (NULL);
	}
	if (pthread_mutex_init(&(*mutex)->print_lock_flag_mutex, NULL))
	{
		pthread_mutex_destroy(&(*mutex)->print_mutex);
		pthread_mutex_destroy(&(*mutex)->finish_mutex);
		return (NULL);
	}
	if (!ph_init_array_mutex(*mutex, num_of_philosophers))
	{
		pthread_mutex_destroy(&(*mutex)->print_mutex);
		pthread_mutex_destroy(&(*mutex)->finish_mutex);
		pthread_mutex_destroy(&(*mutex)->print_lock_flag_mutex);
		return (NULL);
	}
	return (mutex);
}

t_info	*ph_init_info(int argc, char *argv[])
{
	t_info	*info;
	int		i;

	i = 0;
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->num_of_philosophers = ph_atoi(argv[1]);
	info->time_to_die = ph_atoi(argv[2]);
	info->time_to_eat = ph_atoi(argv[3]);
	info->time_to_sleep = ph_atoi(argv[4]);
	if (argc == 6)
		info->time_to_must_eat = ph_atoi(argv[5]);
	else
		info->time_to_must_eat = -1;
	info->start_time = ph_get_time();
	return (info);
}

t_philo	*ph_init_philo(t_info *info, t_mutex *mutex)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philosophers);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < info->num_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].sleep_count = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % info->num_of_philosophers;
		philo[i].last_eat = ph_get_time();
		philo[i].eat_count = 0;
		philo[i].info = ph_copy_info(info);
		philo[i].mutex = mutex;
		i++;
	}
	return (philo);
}
