#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (print_err("Error: invalid arguments", 1));
	info = ph_init_info(argc, argv);
	if (!info)
		return (print_err("Error: malloc failed", 1));
	// dbg_print_info(info);
	philo = ph_init_philo(info);
	if (!philo)
	{
		free(info);
		return (print_err("Error: malloc failed", 1));
	}
	// dbg_print_philos(info, philo);
	if (ph_philo_start(philo))
	{
		free_all(info, philo);
		return (print_err("Error: pthread failed", 1));
	}
	return (0);
}
