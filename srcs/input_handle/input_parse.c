#include <structs.h>
#include <stdio.h>
#include <philo_atoi.h>

static int	print_startup_error(int argc)
{
	if (argc < 5)
		printf("Not enough arguements: Refer to this example\n");
	else if (argc > 6)
		printf("Too many arguements: Refer to this example\n");
	printf("\"./philo number_of_philosophers time_to_die");
	printf(" time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\"\n");
	printf("The last being optional");
	return (FAILURE);
}

int	print_input_errors(char *str, int error_code)
{
	if (error_code == Letters)
		printf("[%s] is not a string of only digit characters\n", str);
	else if (error_code == Too_Small)
		printf("[%s] is too small of a number\n", str);
	else if (error_code == Too_Big)
		printf("[%s] is exceeding INT_MAX\n", str);
	else if (error_code == Malloc_Error)
		printf("There was a Malloc Error during start up\n");
	else if (error_code == Lock_Error)
		printf("There was a Lock Error during start up\n");
	return (FAILURE);
}

int	input_parse(int argc, char *argv[], t_input *input)
{
	if (argc < 5 || argc > 6)
		return (print_startup_error(argc));
	input->min_meals = -1;
	input->num_philos = philo_atoi(argv[1]);
	if (input->num_philos <= 0)
		return (print_input_errors("Philospher Amount", input->num_philos));
	input->tt_die = philo_atoi(argv[2]);
	if (input->tt_die <= 0)
		return (print_input_errors("Time to Die", input->tt_die));
	input->tt_eat = philo_atoi(argv[3]);
	if (input->tt_eat <= 0)
		return (print_input_errors("Time to Eat", input->tt_eat));
	input->tt_sleep = philo_atoi(argv[4]);
	if (input->tt_sleep <= 0)
		return (print_input_errors("Time to Sleep", input->tt_sleep));
	if (argc == 5)
		return (SUCCESS);
	input->min_meals = philo_atoi(argv[5]);
	if (input->min_meals <= 0)
		return (print_input_errors("Minimum Meals", input->min_meals));
	return (SUCCESS);
}