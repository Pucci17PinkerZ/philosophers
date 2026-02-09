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
		// pthread_create();
		i++;
	}
	return (0);
}

// void	*routine(void *table)
// {
	
// 	return (0);
// }
