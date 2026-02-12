/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:55:41 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/06 15:20:07 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_data(void *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
	return ;
}

void	handle_message(char *msg, t_philo *philo, int id)//checker handle message 
{
	long	time;

	time = (get_current_time() - philo->table->start_time);
	pthread_mutex_lock(philo->table->death_mutex);
	if (philo->table->dead_routine == false)
	{
		pthread_mutex_lock(philo->table->write_mutex);//mettre un mutex et check si dead routine est true
		printf("time『%ld』 philo[%d], %s",time , id, msg);
		pthread_mutex_unlock(philo->table->write_mutex);
	}
	pthread_mutex_unlock(philo->table->death_mutex);
}

long	get_current_time(void)
{
	struct timeval	time;
	long			current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}
