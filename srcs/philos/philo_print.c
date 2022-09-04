#include <unistd.h>
#include <colors.h>
#include <structs.h>
#include <stdio.h>
#include <philo_times.h>
#include <philo_actions.h>

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

void	print_status(int num, t_philo *philo, int state, pthread_mutex_t *l)
{
	char *color;
	size_t time;

	time = current_time() - philo->main->start;
	color = color_define(num);
	pthread_mutex_lock(l);
	if (philo->main->finished != 0)
	{
		pthread_mutex_unlock(l);
		return ;
	}
	if (state == Eating)
		printf("%s%zu %d is eating\n", color, time, num);
	else if (state == Sleeping)
		printf("%s%zu %d is sleeping\n", color, time, num);
	else if (state == Grab_Fork)
		printf("%s%zu %d has taken a fork\n", color, time, num);
	else if (state == Died)
	{
		printf("%s%zu %d died\n", color, time, num);
		philo->main->finished++;
	}
	else if (state == Thinking)
		printf("%s%zu %d is thinking\n", color, time, num);
	else if (state == Over)
	{
		printf("%s%zu %d has eaten all meals\n", color, time, num);
		philo->main->finished++;
	}
	pthread_mutex_unlock(l);
}