#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef int t_bool;

typedef struct	s_info
{
	int		num_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_must_eat;
	long	start_time;
}			t_info;

typedef struct 	s_mutex
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	finish_mutex;
	t_bool			finish;
	pthread_mutex_t	*fork_mutex;
	t_bool			*fork;
	pthread_mutex_t	*death_mutex;
	t_bool			*death;
}					t_mutex;

typedef struct	s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	long		last_eat;
	int			eat_count;
	int			sleep_count;
	t_info		*info;
	t_mutex		*mutex;
	pthread_t	thread;
}				t_philo;

int		ph_eat(t_philo *philo);
int		ph_sleep(t_philo *philo);
int		ph_think(t_philo *philo);
int		ph_die(t_philo *philo);
int		ph_put_up_fork(t_philo *philo, int fork_num);
int		ph_put_down_fork(t_philo *philo, int fork_num);
void	*ph_do(void *arg);
int		ph_check_finish(t_philo *philo);
int		ph_philo_start(t_philo *philo);

int		ph_atoi(const char *str);
long	ph_get_time(void);
int		ph_print(t_philo *philo, char *status);
int		ph_flow_time(long long time);
t_info	*ph_copy_info(t_info *info);

t_info	*ph_init_info(int argc, char *argv[]);
t_mutex	*ph_init_mutex_info(int num_of_philosophers);
t_philo	*ph_init_philo(t_info *info, t_mutex *mutex);

int		print_err(char *str, int exit_num);

void	free_mutex(t_philo *philo);
void	free_philo(t_philo *philo);
void	free_all(t_philo *philo);

void	dbg_print_philos(t_info *info, t_philo *philo);
void	dbg_print_info(t_info *info);
void	dbg_print_mutex(t_philo *philo);
#endif
