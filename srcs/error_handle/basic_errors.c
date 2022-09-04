/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_errors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 16:12:09 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/01 19:28:45 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <basic_errors.h>
#include <philo_itoa.h>
#include <stdio.h>
#include <stdlib.h>

int	basic_error(int argc)
{
	if (argc < 5)
		printf("Not enough arguements\n");
	else if (argc > 6)
		printf("Too many arguements\n");
	else 
		return (SUCCESS);
	printf("Correct format is: \n\"./philo number_of_philosophers time_to_die");
	printf(" time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\"\n");
	printf("The last being optional");
	return (FAILURE);
}

int	write_error(char *str, int num)
{
	if (num == SMALL_INT)
		printf("[%s] is not high enough\n", str);
	else if (num == INVALID_INT)
		printf("[%s] is not a valid number\n", str);
	else if (num == BIG_INT)
		printf("[%s] exceeds maximum integer\n", str);
	else if (num == MALLOC_ERROR)
		printf("There was a malloc failure in set up\n");
	return (FAILURE);
}

int	input_error(int argc, char *argv[], t_all *input)
{
	input->meals = -1;
	input->finished = 0;
	input->num_philos = philo_atoi(argv[1]);
	if (input->num_philos < 1)
		return (write_error("Number of Philsophers", input->num_philos));
	input->die = philo_atoi(argv[2]);
	if (input->die < 0)
		return (write_error("Time to Die", input->die));
	input->eat = philo_atoi(argv[3]);
	if (input->eat < 0)
		return (write_error("Time to Eat", input->eat));
	input->sleep = philo_atoi(argv[4]);
	if (input->sleep < 0)
		return (write_error("Time to Sleep", input->sleep));
	if (argc == 5)
		return (SUCCESS);
	input->meals = philo_atoi(argv[5]);
	if (input->meals < 1)
		return (write_error("Amount of Meals Required", input->meals));
	return (SUCCESS);
}
