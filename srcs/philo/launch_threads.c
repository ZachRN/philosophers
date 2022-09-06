#include <structs.h>
#include <input_parse.h>
#include <stdlib.h>
#include <time_utils.h>
#include <philo_print_status.h>
#include <philo_individual.h>

#include <stdio.h>

void	await_thread_deaths(t_input input, pthread_t *id)
{
	int i;

	i = 0;
	while (i < input.num_philos)
	{
		pthread_join(id[i], NULL);
		i++;
	}
}

void	grim_reaper(t_philo *philos, pthread_t *id, t_input input)
{
	int i;
	size_t time;

	my_sleep(20);
	while (TRUE)
	{
		i = 0;
		while (i < input.num_philos)
		{
			pthread_mutex_lock(&philos[i].mutexs->non_malloc[death]);		
			time = time_in_ms();
			if (time >= philos[i].last_eat &&
				time - philos[i].last_eat > philos[i].tt_die)
			{
				philos[i].mutexs->has_finished++;
				print_status(&philos[i], Dying);
				return (void)(await_thread_deaths(input, id));
			}
			pthread_mutex_unlock(&philos[i].mutexs->non_malloc[death]);
			i++;
		}
		my_sleep(5);
	}
}

void	creation_error(t_philo *philos, pthread_t *id, int got_to)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philos[0].mutexs->non_malloc[death]);
	philos->mutexs->has_finished++;
	pthread_mutex_unlock(&philos[0].mutexs->non_malloc[death]);
	while (i < got_to)
	{
		pthread_join(id[i], NULL);
		i++;
	}
	free(id);
}

int	launch_threads(t_philo *philos, t_input input)
{
	int	i;
	int	error;
	pthread_t *id;

	id = malloc(sizeof(pthread_t) * input.num_philos);
	if (!id)
	{
		print_input_errors(NULL, Malloc_Error);
		return (FAILURE);
	}
	i = 0;
	while (i < input.num_philos)
	{
		error = pthread_create(&id[i], NULL, individual, (void *)&(philos[i]));
		if (error != SUCCESS)
		{
			creation_error(philos, id, i);
			return (FAILURE);
		}
		i++;
	}
	grim_reaper(philos, id, input);
	return (SUCCESS);
}
