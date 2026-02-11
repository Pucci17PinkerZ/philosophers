/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 15:20:07 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		if (check_dead(table) || check_meals(table))
			break ;
	}
	return (NULL);
}
int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->table->meal_mutex);
	if (get_current_time - philo->last_meal > philo->table->time_to_eat)
	{
			pthread_mutex_unlock(philo->table->meal_mutex);

		return (1);
	}
	pthread_mutex_unlock(philo->table->meal_mutex);
	return (0);
}

int	check_dead(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (is_dead(table->philo[i]))
		{
			handle_message("has died 💀", table->philo[i], table->philo[i]->id);
			pthread_mutex_lock(table->death_mutex);
			table->philo[i]->is_dead = true;
			pthread_mutex_unlock(table->death_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_meals(t_table *table)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	while (i < table->nbr_of_philo)
	{
		pthread_mutex_lock(table->meal_mutex);
		if (table->philo[i]->meal_eaten >= table->max_meal)
			full++;
		i++;
		pthread_mutex_unlock(table->meal_mutex);
	}
	if (full == table->nbr_of_philo)
	{
		pthread_mutex_lock(table->dead_routine);
		table->dead_routine = true;
		pthread_mutex_unlock(table->dead_routine);
		return (1);
	}
	return (0);
}
int	stop_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->table->death_mutex);
	if (philo->is_dead == true)
	{
		pthread_mutex_unlock(philo->table->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->table->death_mutex);
	return (0);
}
