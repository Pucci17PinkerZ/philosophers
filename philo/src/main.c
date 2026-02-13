/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 15:20:07 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	set_data(&table, sizeof(t_table));
	(void)ac;
	if (check_args(&table, av + 1))
		return (1);
	if (setup_struct(&table))
		return (1);
	init_routine(&table);
	join_all_thread(&table);
	clean_exit(&table);
	return (0);
}

int	init_routine(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (pthread_create(&table->philo_tab[i]->thread_id, NULL,
				routine, (void *)table->philo_tab[i]))
			return (printf("error philo thread creation\n"), 1);
		i++;
	}
	if (pthread_create(&table->monitor, NULL, monitor_routine, (void *)table))
		return (printf("error monitor thread creation\n"), 1);
	return (0);
}

int	join_all_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (pthread_join(table->philo_tab[i]->thread_id, NULL))
			return (printf("error philo_thread join\n"), 1);
		i++;
	}
	if (pthread_join(table->monitor, NULL))
		return (printf("error monitor_thread join\n"), 1);
	return (0);
}
