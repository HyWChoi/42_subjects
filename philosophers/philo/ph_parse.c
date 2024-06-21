/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:36 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/21 10:52:05 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ph_strlen(const char *str)
{
	size_t	a;

	a = 0;
	if (!str || !*str)
		return (0);
	while (*(str + a))
		a++;
	return (a);
}

void	ph_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ph_set_value_with_index(t_info *info, char *str, int count)
{
	if (count == 0)
		info->num_of_philosophers = ph_atoi(str);
	else if (count == 1)
		info->time_to_die = ph_atoi(str);
	else if (count == 2)
		info->time_to_eat = ph_atoi(str);
	else if (count == 3)
		info->time_to_sleep = ph_atoi(str);
	else if (count == 4)
	{
		info->time_to_must_eat = ph_atoi(str);
		info->is_have_must_eat = TRUE;
	}
}

t_info	*ph_set_input_to_info(t_info *info, int argc, char *argv[])
{
	int		i;
	int		k;
	size_t	count_split;
	char	**split;

	i = 1;
	k = 0;
	count_split = 0;
	while (i < argc)
	{
		split = ph_split(argv[i], ' ');
		while (split[k])
			ph_set_value_with_index(info,
				split[k++], count_split++);
		i++;
		k = 0;
		ph_free_split(split);
	}
	if (count_split != 5 && count_split != 4)
		return (NULL);
	if (count_split == 4)
		info->time_to_must_eat = -1;
	info->start_time = ph_get_time();
	return (info);
}
