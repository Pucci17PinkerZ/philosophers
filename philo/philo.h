/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:44:03 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/02 11:24:39 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				nbr_philo;
	pthread_mutex_t	*printf_id;
	t_philo			*philo_tab;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meal_eaten;
	long			last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
}	t_philo;

#endif