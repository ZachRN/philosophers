#include <structs.h>
#include <init_mutexs.h>

int	program_clean_up(t_mutexs *mutexs, t_philo *philo, int ret_val, int philos)
{
	pthread_mutex_destroy(&mutexs->non_malloc[print]);
	pthread_mutex_destroy(&mutexs->non_malloc[death]);
	lock_clean_up(mutexs->forks, philos);
	free(philo);
	return (ret_val);
}

int	main(int argc, char *argv[])
{
	t_input		input;
	t_mutexs	mutexs;
	t_philo		*philo;

	if (input_parse(argc, argv, &input) == FAILURE)
		return (FAILURE);
	if (init_shared_mutexs(input, &mutexs) == FAILURE)
		return (FAILURE);
	philo = init_philos(input, &mutexs);
	if (!philo)
		return program_clean_up(&mutexs, philo, FAILURE, input.num_philos);
	if (launch_threads(philo) == FAILURE)
		return program_clean_up(&mutexs, philo, FAILURE, input.num_philos);
	return program_clean_up(&mutexs, philo, SUCCESS, input.num_philos);
}
	