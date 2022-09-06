#include <structs.h>
#include <time_utils.h>
#include <colors.h>

static char	*color_define(int philo)
{
	int i;

	i = philo % 7;
	if (i == 1)
		return (RED);
	else if (i == 2)
		return (GREEN);
	else if (i == 3)
		return (YELLOW);
	else if (i == 4)
		return (BLUE);
	else if (i == 5)
		return (PURPLE);
	else if (i == 6)
		return (CYAN);
	return (WHITE);
}

void	print_status(int philo_nbr, int state, size_t start, t_mutexs *mutexs)
{
	size_t	time;
	char	*color;

	time = time_in_ms() - start;
	color = color_define(philo_nbr);
	pthread_mutex_lock(&mutexs->non_malloc[print]);
	if (state == Eating)
		printf("%s%zu %d is eating\n", color, time, philo_nbr);
	else if (state == Sleeping)
		printf("%s%zu %d is sleeping\n", color, time, philo_nbr);
	else if (state == Grab_Fork)
		printf("%s%zu %d has taken a fork\n", color, time, philo_nbr);
	else if (state == Thinking)
		printf("%s%zu %d is thinking\n", color, time, philo_nbr);
	else if (state == Dying)
		printf("%s%zu %d has died\n", color, time, philo_nbr);
	pthread_mutex_unlock(&mutexs->non_malloc[print]);
}