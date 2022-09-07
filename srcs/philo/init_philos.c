#include <structs.h>
#include <input_parse.h>
#include <time_utils.h>
#include <stdlib.h>


#include <stdio.h>
t_philo	make_philo(t_input input, t_mutexs *mutexs, int philo_n, size_t time)
{
	t_philo to_return;

	to_return.philo_nbr = philo_n;
	to_return.left_fork = philo_n;
	to_return.right_fork = (philo_n + 1) % input.num_philos;
	to_return.tt_eat = (size_t)input.tt_eat;
	to_return.tt_die = (size_t)input.tt_die;
	to_return.tt_sleep = (size_t)input.tt_sleep;
	to_return.has_eaten = 0;
	to_return.t_meals = input.min_meals;
	to_return.mutexs = mutexs;
	to_return.program_start = time;
	to_return.last_eat = time;
	return (to_return);
}

t_philo *init_philos(t_input input, t_mutexs *mutexs)
{
	int		i;
	t_philo *philos;
	size_t	time;

	philos = malloc(sizeof(t_philo) * input.num_philos);
	if (!philos)
	{
		print_input_errors(NULL, Malloc_Error);
		return (NULL);
	}
	i = 0;
	time = time_in_ms(); 
	while (i < input.num_philos)
	{
		philos[i] = make_philo(input, mutexs, i, time);
		i++;
	}
	return (philos);
}