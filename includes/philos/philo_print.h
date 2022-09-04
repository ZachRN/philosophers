#ifndef PHILO_PRINT_H
# define PHILO_PRINT_H

#include <unistd.h>
#include <pthread.h>
#include <structs.h>

void	print_status(int num, t_philo *philo, int state, pthread_mutex_t *l);

#endif