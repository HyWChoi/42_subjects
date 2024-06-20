/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:16 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:37:17 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	*philo;
	t_mutex	*mutex;

	philo = NULL;
	mutex = NULL;
	if (argc != 5 && argc != 6)
		return (ph_print_err("Error: Invalid arguments", 1));
	if (!ph_set_info(&info, argc, argv))
		return (ph_print_err("Error: Invalid arguments", 1));
	if (!ph_set_start(info, &mutex, &philo))
		return (ph_print_err("Error: Failed to start", 1));
	if (ph_philo_start(philo))
	{
		ph_clean_resources(info, mutex, philo);
		return (ph_print_err("Error: Failed to start", 1));
	}
	ph_clean_resources(info, mutex, philo);
	return (0);
}
