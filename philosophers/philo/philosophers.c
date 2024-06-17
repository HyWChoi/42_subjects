#include "philosophers.h"

static void *ph_set_start(t_info *info, t_mutex **mutex, t_philo **philo)
{
	*mutex = ph_init_mutex_info(info->num_of_philosophers);
	if (!mutex)
		return (NULL);
	*philo = ph_init_philo(info, *mutex);
	if (!philo)
		return (NULL);
	return (philo);
}

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	*philo;
	t_mutex	*mutex;

	philo = NULL;
	mutex = NULL;
	if (argc != 5 && argc != 6)
		return (print_err("Error: invalid arguments", 1));
	info = ph_init_info(argc, argv);
	if (!info)
		return (print_err("Error: malloc failed", 1));
	if (!ph_vaild_info(info))
		return (print_err("Error: invalid arguments", 1));
	if (!ph_set_start(info, &mutex, &philo))
		return (print_err("Error: malloc failed", 1));
	if (ph_philo_start(philo))
		return (print_err("Error: pthread failed", 1));
	return (0);
}
