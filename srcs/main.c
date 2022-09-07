/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:36:20 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/07 14:00:46 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <init_mutexs.h>
#include <input_parse.h>
#include <init_philos.h>
#include <launch_threads.h>
#include <stdlib.h>

int	program_clean_up(t_mutexs *mutexs, t_philo *philo, int ret_val, int philos)
{
	pthread_mutex_destroy(&mutexs->non_malloc[print]);
	pthread_mutex_destroy(&mutexs->non_malloc[death]);
	lock_clean_up(mutexs, philos);
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
		return (program_clean_up(&mutexs, philo, FAILURE, input.num_philos));
	if (launch_threads(philo, input) == FAILURE)
		return (program_clean_up(&mutexs, philo, FAILURE, input.num_philos));
	return (program_clean_up(&mutexs, philo, SUCCESS, input.num_philos));
}
