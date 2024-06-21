/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:38:24 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/21 10:51:37 by hyeonwch         ###   ########.fr       */
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

void	*ph_memset(void *b, int c, size_t len)
{
	int	i;

	i = 0;
	while (len-- != 0)
		*((unsigned char *)b + i++) = (unsigned char)c;
	return (b);
}

t_info	*ph_set_info(t_info **info, int argc, char *argv[])
{
	*info = (t_info *)malloc(sizeof(t_info));
	if (!*info)
		return (NULL);
	ph_memset(*info, 0, sizeof(t_info));
	(*info)->is_have_must_eat = FALSE;
	if (!ph_set_input_to_info(*info, argc, argv))
	{
		free(*info);
		return (NULL);
	}
	if (!ph_vaild_info(*info))
	{
		free(*info);
		return (NULL);
	}
	return (*info);
}
