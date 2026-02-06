/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:30:17 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 12:32:22 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	i = 0;
	while (s[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup[len] = '\0', (char *)dup);
}
