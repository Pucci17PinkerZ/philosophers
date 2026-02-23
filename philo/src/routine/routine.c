/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 15:20:07 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (!(philo->id % 2))
		usleep(philo->table->time_to_eat / 2);
	while (!stop_routine(philo))
	{
		eat(philo, philo->table->time_to_eat);
		go_sleep(philo, philo->table->time_to_sleep);
		think(philo);
	}
	return (NULL);
}

void	eat(t_philo *philo, long time_to_eat)
{
	pthread_mutex_lock(philo->left_fork);
	handle_message("has taken left fork🍴\n", philo, philo->id);
	if (philo->table->nbr_of_philo == 1)
	{
		usleep(philo->table->time_to_die * 1001);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	handle_message("has taken right fork🍴\n", philo, philo->id);
	pthread_mutex_lock(philo->table->meal_mutex);
	philo->eating = true;
	philo->meal_eaten++;
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->table->meal_mutex);
	handle_message("is eating🍖\n", philo, philo->id);
	usleep(time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(philo->table->meal_mutex);
	philo->eating = false;
	pthread_mutex_unlock(philo->table->meal_mutex);
}

void	go_sleep(t_philo *philo, long time_to_sleep)
{
	handle_message("is sleeping😴\n", philo, philo->id);
	usleep(time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	handle_message("is thinking🤔\n", philo, philo->id);
}
