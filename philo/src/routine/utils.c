
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

void	handle_message(char *msg, t_philo *philo, int id)
{
	pthread_mutex_lock(philo->table->write_mutex);
	printf("time『%ld』 philo[%d], %s", );
	pthread_mutex_unlock(philo->table->write_mutex);
}

long	get_current_time(void);
{
	struct timeval time;
	long	current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}