#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef	struct	s_info
{
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_must_eat;
	long			start_time;
	int				time_to_finish_eat;
	int				finish;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	finish_mutex;
}				t_info;

typedef	struct	s_philo
{
	int		id;
	int		death;
	int		eat_count;
	int		sleep_count;
	int		left_fork;
	int		right_fork;
	int		last_eat;
	int		time_to_must_eat;
	void	*start;
	pthread_t	thread;
	pthread_mutex_t	eating_mutex;
	t_info		*info;
}				t_philo;

int		ph_eat(t_info *info, t_philo *philo);
int		ph_sleep(t_info *info, t_philo *philo);
int		ph_think(t_info *info, t_philo *philo);
int		ph_die(t_info *info, t_philo *philo);
void	*ph_do(void *arg);
int		ph_check_finish(t_info *info, t_philo *philo);
int		ph_philo_start(t_philo *philo);

int		ph_atoi(const char *str);
long	ph_get_time(void);
int		ph_print(t_info *info, t_philo *philo, char *status);
int		ph_flow_time(long long time);

t_info	*ph_init_info(int argc, char *argv[]);
t_philo	*ph_init_philo(t_info *info);

int		print_err(char *str, int exit_num);

void	free_mutex(t_info *info);
void	free_philo(t_philo *philo);
void	free_info(t_info *info);
void	free_all(t_info *info, t_philo *philo);

void	dbg_print_philos(t_info *info, t_philo *philo);
void	dbg_print_info(t_info *info);
#endif
