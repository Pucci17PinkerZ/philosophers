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
