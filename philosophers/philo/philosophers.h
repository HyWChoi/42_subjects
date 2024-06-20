/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:38:31 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/06/20 16:57:27 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef int	t_bool;

typedef struct s_info
{
	int		num_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_must_eat;
	long	start_time;
}	t_info;

typedef struct s_mutex
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	print_lock_flag_mutex;
	t_bool			print_lock_flag;
	pthread_mutex_t	finish_mutex;
	t_bool			finish;
	pthread_mutex_t	*fork_mutex;
	t_bool			*fork;
	pthread_mutex_t	*death_mutex;
	t_bool			*death;
	pthread_mutex_t	*finish_eat_mutex;
	t_bool			*finish_eat;
}	t_mutex;

typedef struct s_philo
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
}	t_philo;

// ph_forks.c
void	ph_put_donw_all_forks(t_philo *philo);
int		ph_put_up_fork(t_philo *philo, int fork_num);
int		ph_put_down_fork(t_philo *philo, int fork_num);
int		ph_try_fork(t_philo *philo, int fork_num);
t_bool	ph_is_available_fork(t_philo *philo, int fork_num);

// ph_eating.c
int		ph_finish_eat(t_philo *philo);
t_bool	ph_is_finish_eat(t_philo *philo);
int		ph_eat(t_philo *philo);
t_bool	ph_check_done_eating(t_philo *philo);

// ph_life.c
t_bool	ph_is_dead(t_philo *philo);
int		ph_die(t_philo *philo);
int		ph_sleep(t_philo *philo);
int		ph_think(t_philo *philo);
void	ph_watcher(t_philo *philo);

// ph_print.c
int		ph_is_lock_print(t_philo *philo);
int		ph_lock_print(t_philo *philo);
int		ph_print(t_philo *philo, char *status);
int		ph_print_err(char *str, int ret);
int		ph_print_die(t_philo *philo);

// ph_excute_check.c
t_bool	ph_is_available_execute(t_philo *philo);
t_bool	check_and_do(t_philo *philo, int (*func)(t_philo *philo));

// ph_mutex.c
t_mutex	*ph_make_mutex(int num_of_philosophers);
void	*ph_alloc_mutex_array(t_mutex **mutex, int num_of_philosophers);
void	*ph_alloc_barriered_value_array(t_mutex **mutex,
			int num_of_philosophers);
void	ph_destroy_mutex(t_mutex *mutex, int num_of_philosophers);

// ph_clean.c
void	ph_destroy_mutex_array(pthread_mutex_t *mutex, int i);
void	ph_clean_mutex(t_mutex *mutex, int num_of_philosophers);
void	ph_clean_philo(t_philo *philo, int num_of_philosophers);
void	ph_clean_resources(t_info *info, t_mutex *mutex, t_philo *philo);
void	ph_free_mutex(t_mutex *mutex);

// ph_init.c
int		ph_init_array_mutex(t_mutex	*mutex, int num_of_philosophers);
void	*ph_mutex_init(t_mutex **mutex, int num_of_philosophers);
t_philo	*ph_init_philo(t_info *info, t_mutex *mutex);

// ph_setup.c
void	ph_set_mutexed_value(t_mutex *mutex, int num_of_philosophers);
void	*ph_set_start(t_info *info, t_mutex **mutex, t_philo **philo);
void	*ph_memset(void *b, int c, size_t len);
t_info	*ph_set_info(t_info **info, int argc, char *argv[]);

// ph_parse.c
void	ph_set_value_with_index(t_info *info, char *str, int count);
void	ph_set_input_to_info(t_info *info, int argc, char *argv[]);
void	ph_free_split(char **split);
size_t	ph_strlen(const char *str);

// ph_utils.c
t_bool	ph_vaild_info(t_info *info, int argc);
t_bool	ph_is_exist_die(t_philo *philo);
int		ph_check_finish(t_philo *philo);
int		ph_force_quit(t_philo *philo);
long	ph_get_time(void);

// ph_thread.c
void	*ph_do(void *arg);
int		ph_thread_create(t_philo *philo);
void	ph_thread_join(t_philo *philo);
int		ph_philo_start(t_philo *philo);

// ph_misc.c
int		ph_skip_spaces(const char *str);
int		ph_atoi(const char *str);
t_bool	ph_str_cmp(char *s1, char *s2);
int		ph_flow_time(long long time);
t_info	*ph_copy_info(t_info *info);

// ph_split.c
char	**ph_split(char const *s, char c);

// dbg_philo.c
void	dbg_print_info(t_info *info);
void	dbg_print_mutex(t_philo *philo);
void	dbg_print_philos(t_info *info, t_philo *philo);

#endif
