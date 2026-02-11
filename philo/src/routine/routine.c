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

int	init_routine(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (pthread_create(table->pthread_tab[i], NULL, routine, (void *)table->philo_tab[i]))
			return (printf("error philo_thread creation"), 1);
		i++;
	}
	if ()//ici créer le thread monitor
	return (0);
}

int	join_all_thread(t_table *table)//ATTENTION ICI il faut donner le thread id au destroy
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (pthread_destroy(table->philo_tab[i]->thread_id, NULL, routine, (void *)table->philo_tab[i]))
			return (printf("error philo_thread destroy"), 1);
		i++;
	}
	if ()//ici destroy le thread monitor
	return (0);
}

void	*routine(void *philou)
{
	t_philo	*philo;

	philo = philo;
	if (philo->id % 2 == 1)
		usleep(1);
	while ()
	eat();
	sleep();
	think();
	return (0);
}
