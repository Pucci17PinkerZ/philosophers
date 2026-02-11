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
