#include <structs.h>
#include <philo_times.h>
#include <philo_print.h>
#include <philo_death.h>
#include <philo_eat.h>

#include <stdio.h>

void	sleep_think(t_philo *philo)
{
	print_status(philo, Sleeping);
	my_sleep(philo->sleep);
	print_status(philo, Thinking);
}

void	odd_philo(t_philo *philo)
{
	while (1)
	{
		start_eat_odd(philo);
		sleep_think(philo);
		pthread_mutex_lock(philo->main->m_dead);
		if (philo->main->finished > 0)
		{
			pthread_mutex_unlock(philo->main->m_dead);
			break ;
		}
		pthread_mutex_unlock(philo->main->m_dead);
	}
}

void	even_philo(t_philo	*philo)
{
	while (1)
	{
		start_eat_even(philo);
		sleep_think(philo);
		pthread_mutex_lock(philo->main->m_dead);
		if (philo->main->finished > 0)
		{
			pthread_mutex_unlock(philo->main->m_dead);
			break ;
		}
		pthread_mutex_unlock(philo->main->m_dead);
	}
}

void	*indiv(void *content)
{
	t_philo *philo;

	philo = (t_philo *)content;
	pthread_mutex_lock(philo->main->m_dead);
	philo->last_meal = current_time();
	pthread_mutex_unlock(philo->main->m_dead);
	if (philo->philo % 2 == 0)
		even_philo(philo);
	else
		odd_philo(philo);
	return (NULL);
}