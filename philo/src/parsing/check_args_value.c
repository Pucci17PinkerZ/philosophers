/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 15:26:35 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_value(t_table *table, char **args)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (args[i])
	{
		if (is_arg_nbr(args[i]))
			return (1);
		nbr = atoll(args[i]);
		if (nbr == -1)
			return (1);
		set_table_values(table, nbr, i);
		i++;
	}
	if (table->nbr_of_philo > MAX_PHILO)
		return (1);
	return (0);
}

void	set_table_values(t_table *table, int nbr, int i)
{
	if (i == 0)
	{
		table->nbr_of_philo = nbr;
	}
	else if (i == 1)
	{
		table->time_to_die = nbr;
	}
	else if (i == 2)
	{
		table->time_to_eat = nbr;
	}
	else if (i == 3)
	{
		table->time_to_sleep = nbr;
	}
	else
	{
		table->max_meal = nbr;
	}
}

int	is_arg_nbr(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

long long	atoll(const char *nptr)
{
	long long	i;
	long		sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if ((res * sign) > 2147483647)
			return (-1);
		i++;
	}
	return (res * sign);
}
