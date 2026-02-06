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
	//checker chaque élément dans le tableau dans une boucle while
	//free les éléments seulements à la sortie
	//si le chiffre est juste le transformer de char à int
	// l'assigner a la valeur de i avec des conditions dans l'emplacement souhaité dans la struct
	//puis le parsing est terminé
}


long long	ft_atoll(const char *nptr)
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
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (res * sign);
		i++;
	}
	return (res * sign);
}

int	check_nbr(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}
