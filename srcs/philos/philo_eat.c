#include <structs.h>
#include <philo_print.h>
#include <philo_times.h>

void	start_eat_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->m_forks[philo->fork_left]);
	print_status(philo, Grab_Fork);
	pthread_mutex_lock(&philo->main->m_forks[philo->fork_right]);
	print_status(philo, Grab_Fork);
	print_status(philo, Eating);
	my_sleep(philo->eat);
	pthread_mutex_lock(philo->main->m_dead);
	philo->meals++;
	philo->last_meal = current_time();
	pthread_mutex_unlock(philo->main->m_dead);
	pthread_mutex_unlock(&philo->main->m_forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->main->m_forks[philo->fork_right]);
}

void	start_eat_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->m_forks[philo->fork_right]);
	print_status(philo, Grab_Fork);
	pthread_mutex_lock(&philo->main->m_forks[philo->fork_left]);
	print_status(philo, Grab_Fork);
	print_status(philo, Eating);
	my_sleep(philo->eat);
	pthread_mutex_lock(philo->main->m_dead);
	philo->meals++;
	philo->last_meal = current_time();
	pthread_mutex_unlock(philo->main->m_dead);
	pthread_mutex_unlock(&philo->main->m_forks[philo->fork_right]);
	pthread_mutex_unlock(&philo->main->m_forks[philo->fork_left]);
}