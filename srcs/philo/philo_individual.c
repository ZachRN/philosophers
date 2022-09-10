/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_individual.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 13:20:12 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/10 14:40:23 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <time_utils.h>
#include <philo_print_status.h>

int	is_over(t_philo *philo, int state)
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

void	meal_increase(t_philo *philo)
{
	philo->has_eaten++;
	if (philo->has_eaten == philo->t_meals)
	{
		philo->mutexs->total_finished++;
		philo->has_eaten++;
	}
	if (philo->mutexs->total_finished == philo->mutexs->num_philos)
		philo->mutexs->has_finished++;
}

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutexs->forks[philo->left_fork]);
	if (is_over(philo, Fork) == TRUE)
	{
		pthread_mutex_unlock(&philo->mutexs->forks[philo->left_fork]);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->mutexs->forks[philo->right_fork]);
	if (is_over(philo, Fork) == TRUE || is_over(philo, Eating) == TRUE)
	{
		pthread_mutex_unlock(&philo->mutexs->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->mutexs->forks[philo->right_fork]);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->mutexs->non_malloc[death]);
	philo->last_eat = time_in_ms();
	meal_increase(philo);
	pthread_mutex_unlock(&philo->mutexs->non_malloc[death]);
	my_sleep(philo->tt_eat);
	pthread_mutex_unlock(&philo->mutexs->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutexs->forks[philo->right_fork]);
	return (TRUE);
}

int	philo_sleep_think(t_philo *philo)
{
	if (is_over(philo, Sleeping) == TRUE)
		return (FALSE);
	my_sleep(philo->tt_sleep);
	if (is_over(philo, Thinking) == TRUE)
		return (FALSE);
	return (TRUE);
}

void	*individual(void *content)
{
	t_philo	*philo;

	philo = (t_philo *)content;
	pthread_mutex_lock(&philo->mutexs->non_malloc[death]);
	philo->last_eat = time_in_ms();
	pthread_mutex_unlock(&philo->mutexs->non_malloc[death]);
	if (philo->philo_nbr % 2 == 0)
		my_sleep(5);
	while (1)
	{
		if (philo_eat(philo) == FALSE)
			break ;
		else if (philo_sleep_think(philo) == FALSE)
			break ;
	}
	return (NULL);
}
