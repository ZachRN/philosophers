#include <structs.h>
#include <time_utils.h>

void	philo_actions(t_philo *philo)
{
	
}

void	*individual(void *content)
{
	t_philo *philo;
	
	philo = (t_philo *)content;
	pthread_mutex_lock(&philo->mutexs->non_malloc[death]);
	philo->last_eat = time_in_ms();
	pthread_mutex_unlock(&philo->mutexs->non_malloc[death]);
	if (philo->philo_nbr % 2 == 0)
		my_sleep(5);
	philo_actions(philo);
	return (NULL);
}