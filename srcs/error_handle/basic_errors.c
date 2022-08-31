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

int	input_error(int argc, char *argv[])
{

}