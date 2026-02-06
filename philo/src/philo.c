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
	if (check_arg(&table, av + 1))
		return (1);
	// init(table);

	// routine(table);
	return (0);
}



// int	init(t_philo *philo)
// {
// 	//créer  un tableau avec tout mes philo
// 	//assigner les fourchette gauche droite a chque philo
// }

// int	manage_routine(t_philo *philo)//on va donner cette fonction a thread_create
// {
	
// }

// void	start_routine_thread()
// {
	
// }


// void	check_philo_life()//ici on va lancer un thread tout seul pour checker si les philo sont dead ou pas
// {

// }
