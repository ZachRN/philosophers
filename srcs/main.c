#include <structs.h>
#include <basic_errors.h>
#include <stdio.h>
#include <pthread.h>
#include <make_philo.h>
#include <philo_times.h>

#include <unistd.h>
#include <stdlib.h>

void clean_up(t_all *input)
{
	free(input->forks);
	free(input->philo);
	pthread_mutex_destroy(input->check);
	free(input->check);
	pthread_mutex_destroy(input->dead);
	free(input->dead);
	pthread_mutex_destroy(input->print);
	free(input->print);
}

void check_leaks()
{
	system("leaks -q philo");
}

int main(int argc, char *argv[])
{
	t_all		input;

	atexit(check_leaks);
	if (basic_error(argc) == FAILURE)
		return (1);
	if (input_error(argc, argv, &input) == FAILURE)
		return (1);
	if (init_philos(&input) == FAILURE)
		return (write_error(NULL, MALLOC_ERROR));
	if (init_mutexs(&input) == FAILURE)
		return (write_error(NULL, MALLOC_ERROR));
	if (launch_threads(&input) == FAILURE)
		input.finished++;
	clean_up(&input);
	return (0);
}
