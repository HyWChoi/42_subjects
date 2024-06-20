/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:38:02 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:40:24 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_mutex	*ph_make_mutex(int num_of_philosophers)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!ph_alloc_mutex_array(&mutex, num_of_philosophers))
		return (NULL);
	if (!ph_alloc_barriered_value_array(&mutex, num_of_philosophers))
		return (NULL);
	if (!ph_mutex_init(&mutex, num_of_philosophers))
	{
		ph_free_mutex(mutex);
		return (NULL);
	}
	ph_set_mutexed_value(mutex, num_of_philosophers);
	return (mutex);
}

void	*ph_alloc_mutex_array(t_mutex **mutex, int num_of_philosophers)
{
	(*mutex)->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_of_philosophers);
	if (!(*mutex)->fork_mutex)
		return (NULL);
	(*mutex)->death_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_of_philosophers);
	if (!(*mutex)->death_mutex)
	{
		free((*mutex)->fork_mutex);
		return (NULL);
	}
	(*mutex)->finish_eat_mutex = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * num_of_philosophers);
	if (!(*mutex)->finish_eat_mutex)
	{
		free((*mutex)->fork_mutex);
		free((*mutex)->death_mutex);
		return (NULL);
	}
	return (mutex);
}

void	*ph_alloc_barriered_value_array(t_mutex **mutex,
		int num_of_philosophers)
{
	(*mutex)->fork = (t_bool *)malloc(sizeof(t_bool) * num_of_philosophers);
	if (!(*mutex)->fork)
		return (NULL);
	(*mutex)->death = (t_bool *)malloc(sizeof(t_bool) * num_of_philosophers);
	if (!(*mutex)->death)
	{
		free((*mutex)->fork);
		return (NULL);
	}
	(*mutex)->finish_eat = (t_bool *)malloc(
			sizeof(t_bool) * num_of_philosophers);
	if (!(*mutex)->finish_eat)
	{
		free((*mutex)->fork);
		free((*mutex)->death);
		return (NULL);
	}
	return (mutex);
}

void	ph_destroy_mutex(t_mutex *mutex, int num_of_philosophers)
{
	int	i;

	i = 0;
	ph_destroy_mutex_array(mutex->fork_mutex, num_of_philosophers - 1);
	ph_destroy_mutex_array(mutex->death_mutex, num_of_philosophers - 1);
	ph_destroy_mutex_array(mutex->finish_eat_mutex, num_of_philosophers - 1);
	pthread_mutex_destroy(&mutex->print_mutex);
	pthread_mutex_destroy(&mutex->print_lock_flag_mutex);
	pthread_mutex_destroy(&mutex->finish_mutex);
}
