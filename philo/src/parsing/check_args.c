/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 15:26:35 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(t_table *table, char **av)
{
	char	**args;


	args = assign_args(av);
	if (!args)
		return (1);
	if (check_args_value(table, args))
		return (free_tab(args, 0), 1);
	return (0);
}

char	**assign_args(char **av)
{
	int	nbr_args;
	char	**args;
	char	**tmp;

	nbr_args = find_args_nbr(av);
	if (nbr_args == -1)
		return (NULL);
	tmp = malloc(sizeof(char *) * (nbr_args + 1));
	if (!tmp)
		return (NULL);
	args = dup_tab(av, tmp, 0);
	if (!args)
		return (free_tab(tmp, 0),free_tab(args, 0), NULL);
	return (args);
}


int	find_args_nbr(char **av)
{
	int	i;
	int		tab_size;
	char	**tab;

	i = 0;
	tab_size = 0;
	while (av[i])
	{
		tab = split(av[i],' ');
		if (!tab)
			return (-1);
		tab_size += tab_len(tab);
		free_tab(tab, 0);
		i++;
	}
	if (tab_size < 4 || tab_size > 5)
		return (printf("args_nbr not ok\n"), -1);
	return (tab_size);
}


int	tab_len(char **tab)
{
	if (!tab || !*tab)
		return (0);
	int	i;
	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

char	**dup_tab(char **av, char **tab, int index)
{
	char	**tmp;
	int		tab_pos;
	int		y;

	tab_pos = 0;
	while (av[index])
	{
		y = 0;
		tmp = split(av[index],' ');
		if (!tmp)
			return (free_tab(tab, 0), NULL);
		while (tmp[y])
		{
			tab[tab_pos] = strdup(tmp[y]);
			if (!tab[tab_pos])
				return free_tab(tab, 0), free_tab(tmp, 0), (NULL);
			tab_pos++;
			y++;
		}
		free_tab(tmp, 0);
		index++;
	}
	return (tab[tab_pos] = NULL, tab);
}
