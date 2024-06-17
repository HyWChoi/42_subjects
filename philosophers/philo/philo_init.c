#include "philosophers.h"

void *ph_alloc_mutex(t_mutex **mutex, int num_of_philosophers)
{
	(*mutex)->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_of_philosophers);
	if (!(*mutex)->fork_mutex)
		return (NULL);
	(*mutex)->death_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_of_philosophers);
	if (!(*mutex)->death_mutex)
		return (NULL);
	(*mutex)->finish_eat_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_of_philosophers);
	if (!(*mutex)->finish_eat_mutex)
		return (NULL);
	return (mutex);
}

void	*ph_alloc_barriered_array(t_mutex **mutex, int num_of_philosophers)
{
	(*mutex)->fork = (t_bool *)malloc(sizeof(t_bool) * num_of_philosophers);
	if (!(*mutex)->fork)
		return (NULL);
	(*mutex)->death = (t_bool *)malloc(sizeof(t_bool) * num_of_philosophers);
	if (!(*mutex)->death)
		return (NULL);
	(*mutex)->finish_eat = (t_bool *)malloc(sizeof(t_bool) * num_of_philosophers);
	if (!(*mutex)->finish_eat)
		return (NULL);
	return (mutex);
}

int	ph_init_mutex_array(pthread_mutex_t	*mutex, int num_of_philosophers)
{
	int	i;

	i = 0;
	while (i < num_of_philosophers)
	{
		if (pthread_mutex_init(&mutex[i], NULL))
			return (i);
		i++;
	}
	return (0);
}

void	*ph_mutex_init(t_mutex **mutex, int num_of_philosophers)
{
	if (ph_init_mutex_array((*mutex)->fork_mutex, num_of_philosophers))
		return (NULL);
	if (ph_init_mutex_array((*mutex)->death_mutex, num_of_philosophers))
		return (NULL);
	if (ph_init_mutex_array((*mutex)->finish_eat_mutex, num_of_philosophers))
		return (NULL);
	if (pthread_mutex_init(&(*mutex)->print_lock_flag_mutex, NULL))
		return (NULL);
	if (pthread_mutex_init(&(*mutex)->finish_mutex, NULL))
		return (NULL);
	if (pthread_mutex_init(&(*mutex)->print_mutex, NULL))
		return (NULL);
	return (mutex);
}

void	ph_set_barriered_value(t_mutex *mutex, int num_of_philosophers)
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

t_mutex	*ph_init_mutex_info(int num_of_philosophers)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!ph_alloc_mutex(&mutex, num_of_philosophers))
		return (NULL);
	if (!ph_alloc_barriered_array(&mutex, num_of_philosophers))
		return (NULL);
	ph_set_barriered_value(mutex, num_of_philosophers);
	return (mutex);
}

t_bool	ph_vaild_info(t_info *info)
{
	if (info->num_of_philosophers < 2)
		return (FALSE);
	if (info->time_to_die < 60)
		return (FALSE);
	if (info->time_to_eat < 60)
		return (FALSE);
	if (info->time_to_sleep < 60)
		return (FALSE);
	if (info->time_to_must_eat < 0)
		return (FALSE);
	return (TRUE);
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
