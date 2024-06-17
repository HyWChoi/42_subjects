#include "philosophers.h"

void	dbg_print_info(t_info *info)
{
	int	i;

	i = 0;
	printf("info->num_of_philosophers = %d\n", info->num_of_philosophers);
	printf("info->time_to_die = %d\n", info->time_to_die);
	printf("info->time_to_eat = %d\n", info->time_to_eat);
	printf("info->time_to_sleep = %d\n", info->time_to_sleep);
	printf("info->time_to_must_eat = %d\n", info->time_to_must_eat);
}

void	dbg_print_mutex(t_philo *philo)
{
	t_mutex	*mutex;
	int		i;

	i = 0;
	mutex = philo->mutex;
	printf("mutex->print_mutex = %p\n", &mutex->print_mutex);
	printf("mutex->fork_mutex = %p\n", mutex->fork_mutex);
	while (i < philo->info->num_of_philosophers)
	{
		printf("mutex->fork[%d] = %d\n", i, mutex->fork[i]);
		i++;
	}
	printf("mutex->finish = %d\n", mutex->finish);
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
		printf("philo[%d].last_eat = %ld\n", i, philo[i].last_eat);
		printf("philo[%d].sleep_count = %d\n", i, philo[i].sleep_count);
		dbg_print_info(philo[i].info);
		dbg_print_mutex(philo + i);
		i++;
	}
}
