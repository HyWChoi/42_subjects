/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_excute_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:46 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:37:47 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ph_is_available_execute(t_philo *philo)
{
	if (ph_check_finish(philo) || ph_is_dead(philo))
		return (FALSE);
	return (TRUE);
}

t_bool	check_and_do(t_philo *philo, int (*func)(t_philo *philo))
{
	if (!ph_is_available_execute(philo))
		return (FALSE);
	if (func(philo))
		return (FALSE);
	return (TRUE);
}
