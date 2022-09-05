#include <structs.h>
#include <basic_errors.h>
#include <stdio.h>
#include <pthread.h>
#include <make_philo.h>
#include <philo_times.h>
#include <mutex_init.h>

#include <unistd.h>
#include <stdlib.h>

void clean_up(t_all *input)
{
	int i;

	i = 0;
	free(input->forks);
	free(input->philo);
	pthread_mutex_destroy(input->m_check);
	free(input->m_check);
	pthread_mutex_destroy(input->m_dead);
	free(input->m_dead);
	pthread_mutex_destroy(input->m_print);
	free(input->m_print);
	while (i < input->num_philos)
	{
		pthread_mutex_destroy(&input->m_forks[i]);
		i++;
	}
	free(input->m_forks);
}

// void m_check_leaks()
// {
// 	system("leaks -q philo");
// }

int main(int argc, char *argv[])
{
	t_all		input;

	// atexit(m_check_leaks);
	if (basic_error(argc) == FAILURE)
		return (1);
	if (input_error(argc, argv, &input) == FAILURE)
		return (1);
	if (init_philos(&input) == FAILURE)
		return (write_error(NULL, MALLOC_ERROR));
	if (malloc_mutexs(&input) == FAILURE)
		return (write_error(NULL, MALLOC_ERROR));
	if (launch_threads(&input) == FAILURE)
		input.finished++;
	clean_up(&input);
	return (0);
}
