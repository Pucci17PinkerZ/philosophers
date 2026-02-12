/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:42:32 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 14:42:43 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*destroy first the mutex then thread,data, fork , philo*/
// void	free_struct(t_table	*table, char letter)
// {
// 	if (letter == 'P')
// 		free_array((void **)table->philo_tab, 0);
// 	if (letter == 'F')
// 		free_array((void **)table->fork_tab, 0);
// 	if (letter == 'M')
// 		//delete tout les mutex
// 	if (letter == 'T')
// 		//detacher les thread qui bloquent
// }

void	free_tab(char **tab, int j)
{
	if (!tab)
		return ;
	while (tab[j])
		j++;
	j++;
	while (j > 0)
		free(tab[--j]);
	free(tab);
}

void	clean_exit(t_table	*table)
{
	if (!table)
		return ;
	//ici table existe
	//clean les threads(philo)
	if (table->philo_tab)
		clean_philo(table);
	free(philo_tab);
	//clean les fork
	if (table->fork_tab)
		clean_fork(table);
	free(fork_tab);
	//clean le moniteur
	if (table->write_mutex)
		free(table->write_mutex);
	if (table->death_mutex)
		free(table->death_mutex);
	if (table->meal_mutex)
		free(table->meal_mutex);
}

void	clean_philo(t_table	*table)
{
	int	i;

	i = 0;
	while (table->philo_tab[i])
	{
		free(table->philo_tab[i]);
		i++;
	}
}
void	clean_fork(t_table	*table)
{
	int	i;

	i = 0;
	while (table->fork_tab[i])
	{
		free(table->fork_tab[i]);
		i++;
	}
}



// void	free_array(void **tab, int j)
// {
// 	if (!tab)
// 		return ;
// 	while (tab[j])
// 		j++;
// 	j++;
// 	while (j > 0)
// 		free(tab[--j]);
// 	free(tab);
// }
