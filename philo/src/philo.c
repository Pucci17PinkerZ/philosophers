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
	printf("----------\n");
	printf("table->nbr_of_philo == %d\n", table.nbr_of_philo);
	printf("table->time_to_die == %ld\n", table.time_to_die);
	printf("table->time_to_eat == %ld\n", table.time_to_eat);
	printf("table->time_to_sleep == %ld\n", table.time_to_sleep);
	printf("table->max_meal == %ld\n", table.max_meal);
	// init_philo(table);

	// routine(table);
	return (0);
}

int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo_tab = malloc(sizeof(t_philo) * (table->nbr_of_philo + 1));
	if (!table->philo_tab)
		return (1);
	while (table->philo_tab[i])
	{
		table->philo_tab[i]->id = i + 1;
		i++;
	}
	table->philo_tab[i] = NULL;
	return (0);
}

	//créer  un tableau avec tout mes philo
	//assigner les fourchette gauche droite a chque philo

// int	manage_routine(t_philo *philo)//on va donner cette fonction a thread_create
// {
	
// }

// void	start_routine_thread()
// {
	
// }


// void	check_philo_life()//ici on va lancer un thread tout seul pour checker si les philo sont dead ou pas
// {

// }
