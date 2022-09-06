#include <structs.h>
#include <unistd.h>
#include <stdlib.h>
#include <input_parse.h>

int	lock_clean_up(t_mutexs *mutexs, int clean_to)
{
	int i;

	i = 0;
	while (i < clean_to)
	{
		pthread_mutex_destroy(&mutexs->forks[i]);
		i++;
	}
	free(mutexs->forks);
	return (FAILURE);
}

static int	init_fork_mutexs(t_input input, t_mutexs *mutexs)
{
	int i;
	int error;

	mutexs->forks = malloc(sizeof(pthread_mutex_t) * input.num_philos);
	if (!mutexs->forks)
	{
		print_input_errors(NULL, Malloc_Error);
		pthread_mutex_destroy(&mutexs->non_malloc[print]);
		pthread_mutex_destroy(&mutexs->non_malloc[death]);
		return (FAILURE);
	}
	i = 0;
	while (i < input.num_philos)
	{
		error = pthread_mutex_init(&mutexs->forks[i], NULL);
		if (error != SUCCESS)
			return (lock_clean_up(mutexs, i));
		i++;
	}
	return (SUCCESS);
}

int	init_shared_mutexs(t_input input, t_mutexs *mutexs)
{
	int	error;

	error = pthread_mutex_init(&mutexs->non_malloc[print], NULL);
	if (error != SUCCESS)
	{
		print_input_errors(NULL, Lock_Error);
		return (FAILURE);
	}
	error = pthread_mutex_init(&mutexs->non_malloc[death], NULL);
	if (error != SUCCESS)
	{
		print_input_errors(NULL, Lock_Error);
		pthread_mutex_destroy(&mutexs->non_malloc[print]);
		return (FAILURE);
	}
	return (init_fork_mutexs(input, mutexs));
}