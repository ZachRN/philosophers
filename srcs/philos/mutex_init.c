/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 17:05:14 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/05 17:21:08 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <basic_errors.h>

static void	remove_forks_error(t_all *input, int got_to)
{
	int i;

	i = 0;
	while (i < got_to)
	{
		pthread_mutex_destroy(&input->m_forks[i]);
		i++;
	}
	return ;
}

static int	init_forks(t_all *input)
{
	int error;
	int i;

	i = 0;
	while (i < input->num_philos)
	{
		error = pthread_mutex_init(&input->m_forks[i], NULL);
		if (error != 0)
		{
			remove_forks_error(input, i);
			return (FALSE);
		}
		i++;
	}
	return (SUCCESS);
}

static int	init_mutexs(t_all *input)
{
	int i;
	int error;
	
	i = 0;
	error = pthread_mutex_init(input->m_check, NULL);
	if (error != 0)
		return (FALSE);
	error = pthread_mutex_init(input->m_dead, NULL);
	if (error != 0)
	{
		pthread_mutex_destroy(input->m_check);
		return (FALSE);
	}
	error = pthread_mutex_init(input->m_print, NULL);
	if (error != 0)
	{
		pthread_mutex_destroy(input->m_check);
		pthread_mutex_destroy(input->m_dead);
		return (FALSE);
	}
	return (init_forks(input));
}

int	malloc_mutexs(t_all *input)
{
	input->m_check = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	input->m_dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	input->m_print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	input->m_forks = malloc(sizeof(pthread_mutex_t *) * input->num_philos);
	if (!input->m_check || !input->m_dead || !input->m_print || !input->m_forks)
	{
		free(input->m_check);
		free(input->m_dead);
		free(input->m_print);
		free(input->m_forks);
		return (FAILURE);
	}
	return (init_mutexs(input));
}