#include <structs.h>
#include <philo_times.h>
#include <philo_print.h>

int is_over(t_philo *philo)
{
	size_t time;
	
	time = current_time();
	pthread_mutex_lock(philo->main->dead);
	if (philo->main->finished != 0)
	{
		pthread_mutex_unlock(philo->main->dead);
		return (TRUE);
	}
	if (philo->meals == philo->main->meals)
	{
		philo->meals++;
		print_status(philo->philo, philo, Over, philo->main->print);
		pthread_mutex_unlock(philo->main->dead);
		return (TRUE);
	}
	if (time - philo->last_meal > philo->main->die)
	{
		print_status(philo->philo, philo, Died, philo->main->print);
		philo->main->finished++;
		pthread_mutex_unlock(philo->main->dead);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->main->dead);
	return (FALSE);
}