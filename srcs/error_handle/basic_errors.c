/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_errors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 16:12:09 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/01 16:12:12 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

int	basic_error(int argc)
{
	if (argc < 5)
		printf("Not enough arguements\n");
	else if (argc > 6)
		printf("Too many arguements\n");
	printf("Correct format is: \n\"./philo number_of_philosophers time_to_die");
	printf("time_to_eat time_to_sleep");
	printf("[number_of_times_each_philosopher_must_eat]\"\n");
	printf("The last being optional");
	return (0);
}

void	write_error(char *str, int num);
{

}

int	input_error(int argc, char *argv[], t_input *input)
{
	input->num_philos = philo_atoi(argv[1]);

	return (1);
}
