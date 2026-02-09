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
#include <stdbool.h>
# include <pthread.h>

// typedef (changer le nom des fonctions ou struct chiantes)
typedef pthread_mutex_t t_mutex;

typedef struct s_data
{
	bool			as_eat;
	bool			as_sleep;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	// pthread_mutex_t	*printf_id;

}	t_data;

typedef struct s_philo
{
	int				id;
	int				meal_eaten;
	long			last_meal;
	t_mutex		*right_fork;
	t_mutex		*left_fork;
	t_data			*data;
}	t_philo;

typedef struct s_table
{
	int				nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_meal;
	t_philo			**philo_tab;
	t_mutex			**fork_tab;
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
void	set_table_values(t_table *table, int nbr, int i);

/* ========================================================================== */
/* ===============================init========================================*/
/* ========================================================================== */
int	setup_struct(t_table *table);
int	init_fork(t_table *table);
int	init_fork_tab(t_table *table);
int	init_philo(t_table *table);


/* ========================================================================== */
/* ===============================routine=====================================*/
/* ========================================================================== */
int	main(int ac, char **av);
int	init_philo(t_table *table);

/*utils*/
void	set_data(void *s, int n);

/* ========================================================================== */
/* ===============================cleaners====================================*/
/* ========================================================================== */
void	free_tab(char **tab, int j);

#endif