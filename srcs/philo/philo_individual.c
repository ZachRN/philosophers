#include <structs.h>
#include <time_utils.h>
#include <philo_print_status.h>

#include <stdio.h>

int		is_over(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->mutexs->non_malloc[death]);
	if (philo->mutexs->has_finished != 0)
	{
		pthread_mutex_unlock(&philo->mutexs->non_malloc[death]);
		return (TRUE);
	}
	print_status(philo, state);
	pthread_mutex_unlock(&philo->mutexs->non_malloc[death]);
	return (FALSE);
}

int		philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutexs->forks[philo->left_fork]);
	if (is_over(philo, Fork) == TRUE)
	{
		pthread_mutex_unlock(&philo->mutexs->forks[philo->left_fork]);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->mutexs->forks[philo->right_fork]);
	if (is_over(philo, Fork) == TRUE)
	{
		pthread_mutex_unlock(&philo->mutexs->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->mutexs->forks[philo->right_fork]);
		return (FALSE);
	}
	if (is_over(philo, Eating) == TRUE)
	{
		pthread_mutex_unlock(&philo->mutexs->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->mutexs->forks[philo->right_fork]);
		return (FALSE);
	}
	my_sleep(philo->tt_eat);
	pthread_mutex_unlock(&philo->mutexs->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutexs->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->mutexs->non_malloc[death]);
	philo->last_eat = time_in_ms();
	pthread_mutex_unlock(&philo->mutexs->non_malloc[death]);
	return (TRUE);
}

int		philo_sleep_think(t_philo *philo)
{
	if (is_over(philo, Sleeping) == TRUE)
		return (FALSE);
	my_sleep(philo->tt_sleep);
	if (is_over(philo, Thinking) == TRUE)
		return (FALSE);
	return (TRUE);
}

void	philo_actions(t_philo *philo)
{
	while (1)
	{
		if (philo_eat(philo) == FALSE)
			return ;
		else if (philo_sleep_think(philo) == FALSE)
			return ;
	}
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