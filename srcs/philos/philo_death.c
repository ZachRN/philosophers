#include <structs.h>
#include <philo_times.h>
#include <philo_print.h>
#include <pthread.h>
#include <stdio.h>

int	either_finished(t_philo *philo)
{
	size_t time;
	
	if (philo->meals == philo->needed_meals)
	{
		// printf("%zu %d has eaten all meals\n", time, philo->philo + 1);
		print_status(philo, Over);
		return (TRUE);
	}
	time = current_time();
	if (time - philo->last_meal > philo->die)
	{
		pthread_mutex_lock(philo->main->m_print);
		time = time - philo->main->start;
		printf("%zu %d died\n",  time, philo->philo + 1);
		pthread_mutex_unlock(philo->main->m_print);
		return (TRUE);
	}
	return (FALSE);
}

void	main_reaper(t_all *input)
{
	int i;
	t_philo *to_check;

	while (1)
	{
		i = 0;
		while (i < input->num_philos)
		{
			pthread_mutex_lock(input->m_dead);
			to_check = &input->philo[i];
			if (either_finished(to_check) == TRUE)
			{
				input->finished++;
				pthread_mutex_unlock(input->m_dead);
				return ;
			}
			pthread_mutex_unlock(input->m_dead);
			i++;
		}
		my_sleep(10);
	}

}