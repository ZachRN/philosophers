#include <structs.h>
#include <stdlib.h>
#include <basic_errors.h>
#include <philo_times.h>
#include <philo_actions.h>
#include <philo_death.h>

#include <stdio.h>

t_philo	assign_philo_start(t_all *input, int i)
{
	t_philo to_return;

	to_return.philo = i;
	to_return.fork_left = i;
	to_return.fork_right = (i + 1) % input->num_philos;
	to_return.die = input->die;
	to_return.eat = input->eat;
	to_return.sleep = input->sleep;
	to_return.meals = 0;
	to_return.needed_meals = input->meals;
	to_return.main = input;
	return (to_return);
}


int	init_philos(t_all *input)
{
	int i;

	i = 0;
	input->forks = (int *)malloc(sizeof(int) * input->num_philos);
	input->philo = malloc(sizeof(t_philo) * input->num_philos);
	if (!input->philo || !input->forks)
	{
		free(input->forks);
		free(input->philo);
		return (MALLOC_ERROR);
	}
	while (i < input->num_philos)
	{
		input->philo[i] = assign_philo_start(input, i);
		i++;
	}
	return (1);
}

int	launch_threads(t_all *input)
{
	int i;
	int error;
	pthread_t *id;

	i = 0;
	input->start = current_time();
	id = (pthread_t *)malloc(sizeof(pthread_t) * input->num_philos);
	if (!id)
		return (write_error(NULL, MALLOC_ERROR));
	while (i < input->num_philos)
	{
		error = pthread_create(&id[i], NULL, indiv, (void *)&input->philo[i]);
		if (error < 0)
			return (FAILURE);
		i++;
	}
	i = 0;
	// main_reaper(input);
	while (i < input->num_philos)
	{
		error = pthread_join(id[i], NULL);
		i++;
	}
	free(id);
	return (SUCCESS);
}