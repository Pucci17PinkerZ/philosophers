/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:44:03 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 15:27:35 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

# define MAX_PHILO 200

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int				id;
	int				meal_eaten;
	long			last_meal;
	bool			eating;
	bool			as_sleep;
	bool			is_dead;
	struct s_table	*table;
	t_mutex			*right_fork;
	t_mutex			*left_fork;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_table
{
	int				nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_meal;
	long			start_time;
	bool			dead_routine;
	t_philo			**philo_tab;
	t_mutex			**fork_tab;
	t_mutex			*write_mutex;
	t_mutex			*death_mutex;
	t_mutex			*meal_mutex;
	pthread_t		monitor;
}	t_table;

/* ========================================================================== */
/* ===============================parsing=====================================*/
/* ========================================================================== */
int			check_args(t_table *table, char **av);
int			check_args_value(t_table *table, char **args);
int			is_arg_nbr(char *arg);
char		**assign_args(char **av);
int			find_args_nbr(char **av);
int			tab_len(char **tab);
char		**dup_tab(char **av, char **tab, int index);
long long	atoll(const char *nptr);
char		**split(char const *s, char c);
void		set_table_values(t_table *table, int nbr, int i);

/* ========================================================================== */
/* ===============================init========================================*/
/* ========================================================================== */
int			setup_struct(t_table *table);
int			init_fork(t_table *table);
int			init_fork_tab(t_table *table);
int			init_philo(t_table *table);
int			init_monitor(t_table *table);

/* ========================================================================== */
/* ===============================routine=====================================*/
/* ========================================================================== */
int			main(int ac, char **av);
int			init_routine(t_table *table);
void		*routine(void *table);
void		eat(t_philo *philo, long time_to_eat);
void		go_sleep(t_philo *philo, long time_to_sleep);
void		think(t_philo *philo);
int			join_all_thread(t_table *table);
void		*monitor_routine(void *data);
int			is_dead(t_philo *philo);
int			check_dead(t_table *table);
int			check_meals(t_table *table);
int			stop_routine(t_philo *philo);

/*utils*/
void		set_data(void *s, int n);
void		handle_message(char *msg, t_philo *philo, int id);
long		get_current_time(void);

/* ========================================================================== */
/* ===============================cleaners====================================*/
/* ========================================================================== */
void		free_tab(char **tab, int j);
void		clean_exit(t_table	*table);
void		clean_philo(t_table	*table);
void		clean_fork(t_table	*table);

#endif