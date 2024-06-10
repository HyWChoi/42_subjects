#include "philosophers.h"

void	dbg_print_info(t_info *info)
{
	printf("info->num_of_philosophers = %d\n", info->num_of_philosophers);
	printf("info->time_to_die = %d\n", info->time_to_die);
	printf("info->time_to_eat = %d\n", info->time_to_eat);
	printf("info->time_to_sleep = %d\n", info->time_to_sleep);
	printf("info->time_to_must_eat = %d\n", info->time_to_must_eat);
	printf("info->time_to_finish_eat = %d\n", info->time_to_finish_eat);
	printf("info->finish = %d\n", info->finish);
}

void	dbg_print_philos(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_of_philosophers)
	{
		printf("philo[%d].id = %d\n", i, philo[i].id);
		printf("philo[%d].left_fork = %d\n", i, philo[i].left_fork);
		printf("philo[%d].right_fork = %d\n", i, philo[i].right_fork);
		printf("philo[%d].last_eat = %d\n", i, philo[i].last_eat);
		printf("philo[%d].eat_count = %d\n", i, philo[i].eat_count);
		printf("philo[%d].sleep_count = %d\n", i, philo[i].sleep_count);
		printf("philo[%d].thread = %p\n", i, philo[i].thread);
		printf("philo[%d].info = %p\n", i, philo[i].info);
		i++;
	}
}
