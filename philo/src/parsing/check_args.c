/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/02 11:27:46 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(t_philo *philo, int ac, char **av)
{
	char	**args;

	if (ac < 4 || ac > 5)
		return (printf("args_nbr not ok"), 1);

	if (assign_args(av, args))
		return (1);
	if (check_nbr_string())
		return (1);

	// if ()
	// 	return (1);
	//transformer les arguments de char à int
	//les ajouter a la struct
	return (0);
}

int	find_args_nbr(char **av)
{
	int	i;
	int		tab_len;
	char	**tab;

	i = 0;
	while (av[i])
	{
		tab = split(av[i],' ');
		if (!tab)
			return (-1);
		tab_len += tab_len(tab);
		free_tab(tab, 0);
		i++;
	}
	return (tab_len);
}


int	tab_len(char **tab)
{
	if (!tab || !*tab)
		return (1);
	int	i;
	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}



char	**assign_args(char **av)
{
	int	i;
	int	nbr_args;
	char	**args;

	nbr_args = find_args_nbr();
	if (nbr_args == -1)
		return (NULL);
	args = malloc(sizeof(char *) * (nbr_args + 1));
	if (!args)
		return (1);
	i = 0;
	while (av[i])
	{

	}
	return ;
}

int	find_args_nbr

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

// int	check_nbr(char *arg)
// {
// 	int	i;

// 	i = 0;
// 	if (arg[0] == '-' || arg[0] == '+')
// 		i++;
// 	if (!arg[i])
// 		return (1);
// 	while (arg[i])
// 	{
// 		if (!ft_isdigit(arg[i]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }