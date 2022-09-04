#include <structs.h>
#include <philo_times.h>
#include <philo_print.h>
#include <philo_death.h>

#include <stdio.h>

static int	grab_forks(t_philo *philo)
{
	while (TRUE)
	{
		if (is_over(philo) == TRUE)
			return (FALSE);
		pthread_mutex_lock(philo->main->check);
		if (philo->main->forks[philo->fork_left] == 0)
		{
			philo->has_left = 1;
			philo->main->forks[philo->fork_left] = 1;
			print_status(philo->philo, philo, Grab_Fork, philo->main->print);
		}
		if (philo->main->forks[philo->fork_right] == 0)
		{
			philo->has_right = 1;
			philo->main->forks[philo->fork_right] = 1;
			print_status(philo->philo, philo, Grab_Fork, philo->main->print);
		}
		pthread_mutex_unlock(philo->main->check);
		if (philo->has_left && philo->has_right)
			return (TRUE);
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->main->check);
	philo->main->forks[philo->fork_left] = 0;
	philo->has_left = 0;
	philo->main->forks[philo->fork_right] = 0;
	philo->has_right = 0;
	pthread_mutex_unlock(philo->main->check);
}

int	start_eat(t_philo *philo)
{
	if (grab_forks(philo) == FALSE)
		return (FALSE);
	if (is_over(philo) == TRUE)
		return (FALSE);	
	print_status(philo->philo, philo, Eating, philo->main->print);
	philo->meals++;
	if (is_over(philo) == TRUE)
		return (FALSE);
	my_sleep(philo->main->eat);
	philo->last_meal = current_time();
	release_forks(philo);
	return (TRUE);
}

int	sleep_think(t_philo *philo)
{
	size_t time;

	time = current_time();
	if (is_over(philo) == TRUE)
		return (FALSE);
	print_status(philo->philo, philo, Sleeping, philo->main->check);
	while (current_time() - time <= philo->main->sleep)
	{
		if (is_over(philo) == TRUE)
			return (FALSE);
		my_sleep(1);
	}
	if (is_over(philo) == TRUE)
		return (FALSE);
	print_status(philo->philo, philo, Thinking, philo->main->check);
	return (TRUE);
}

void	*indiv(void *content)
{
	t_philo *philo;

	philo = (t_philo *)content;
	if (philo->philo % 2)
		my_sleep(250);
	philo->last_meal = current_time();
	while(philo->main->finished == 0)
	{
		if (start_eat(philo) == FALSE)
			break ;
		if (sleep_think(philo) == FALSE)
			break ;
	}
	return (NULL);
}