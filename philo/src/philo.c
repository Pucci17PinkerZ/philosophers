/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/02 11:27:46 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (check_arg(philo, ac, av))
		return (1);
	init(philo);
	routine(philo);
	return (0);
}

int	check_arg(t_philo *philo, int ac, char **av)
{
	if (ac < 4 || ac > 5)
		return (1);
	if (arg_to_int(philo, av))
		return (1);
	//transformer les arguments de char à int
	//les ajouter a la struct
}

int	arg_to_int(t_philo *philo, char **av)
{
	
}

int	init(t_philo *philo)
{
	//créer  un tableau avec tout mes philo
}

int	routine(t_philo *philo)
{
	
}