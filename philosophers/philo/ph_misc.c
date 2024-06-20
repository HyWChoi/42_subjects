/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:59 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 15:39:07 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ph_atoi(const char *str)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return ((int)(nbr));
}

t_bool	ph_str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	if (s1[i] || s2[i])
		return (FALSE);
	return (TRUE);
}

int	ph_flow_time(long long time)
{
	long long	start;

	start = ph_get_time();
	while (ph_get_time() - start < time)
		usleep(100);
	return (0);
}

t_info	*ph_copy_info(t_info *info)
{
	t_info	*new_info;

	new_info = (t_info *)malloc(sizeof(t_info));
	if (!new_info)
		return (NULL);
	new_info->num_of_philosophers = info->num_of_philosophers;
	new_info->time_to_die = info->time_to_die;
	new_info->time_to_eat = info->time_to_eat;
	new_info->time_to_sleep = info->time_to_sleep;
	new_info->time_to_must_eat = info->time_to_must_eat;
	new_info->start_time = info->start_time;
	return (new_info);
}