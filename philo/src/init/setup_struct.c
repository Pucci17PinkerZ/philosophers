/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 15:20:07 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setup_struct(t_table *table)//libérer ici chaque chose si besoin ou au dessus?
{
	if (init_philo(table))
		return (1);
	
	if (init_fork(table))
		return (1);
	/*check*/
	// int i = 0;
	// while (table->philo_tab[i])
	// {
	// 	printf("philo[%d] forkR == %p && forkL == %p\n", i, table->philo_tab[i]->left_fork, table->philo_tab[i]->right_fork);
	// 	i++;
	// }
	// return (0);

	/*----*/
	return (0);
}

int	init_fork(t_table *table)
{
	int	i;

	i = 0;
	if (init_fork_tab(table))
		return (1);
	while (table->philo_tab[i])
	{
		table->philo_tab[i]->left_fork = table->fork_tab[i];
		table->philo_tab[i]->right_fork = table->fork_tab[(i + 1) % table->nbr_of_philo];
		i++;
	}
	return (0);
}

int	init_fork_tab(t_table *table)
{
	int	i;

	i = 0;
	table->fork_tab = malloc(sizeof(t_mutex *) * (table->nbr_of_philo + 1));
	if (!table->fork_tab)
		return (1);
	while (i < table->nbr_of_philo)
	{
		table->fork_tab[i] = malloc(sizeof(t_mutex));
		pthread_mutex_init(table->fork_tab[i], NULL);
		if (!table->fork_tab[i])
			return (1);
		i++;
	}
	table->fork_tab[i] = NULL;
	return (0);
}

int	init_philo(t_table *table) //clean si un problème surviens dans le while
{
	int	i;

	i = 0;
	table->philo_tab = malloc(sizeof(t_philo *) * (table->nbr_of_philo + 1));
	if (!table->philo_tab)
		return (1);
	printf("alloc tab ok\n");
	while (i < table->nbr_of_philo)
	{
		table->philo_tab[i] = malloc(sizeof(t_philo));
			if (!table->philo_tab[i])
				return (1);
		table->philo_tab[i]->id = i + 1;
		i++;
	}
	table->philo_tab[i] = NULL;
	return (0);
}
