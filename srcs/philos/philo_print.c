#include <unistd.h>
#include <colors.h>
#include <structs.h>
#include <stdio.h>
#include <philo_times.h>
#include <philo_actions.h>

// static char	*color_define(int philo)
// {
// 	int i;

// 	i = philo % 7;
// 	if (i == 1)
// 		return (RED);
// 	else if (i == 2)
// 		return (GREEN);
// 	else if (i == 3)
// 		return (YELLOW);
// 	else if (i == 4)
// 		return (BLUE);
// 	else if (i == 5)
// 		return (PURPLE);
// 	else if (i == 6)
// 		return (CYAN);
// 	return (WHITE);
// }

static void	print_statement(int num, int state, size_t time)
{
	if (state == Eating)
		printf("%zu %d is eating\n", time, num);
	else if (state == Sleeping)
		printf("%zu %d is sleeping\n", time, num);
	else if (state == Grab_Fork)
		printf("%zu %d has taken a fork\n", time, num);
	else if (state == Thinking)
		printf("%zu %d is thinking\n", time, num);
}

void	print_status(t_philo *philo, int state)
{
	// char	*color;
	size_t	time;
	int		num;

	num = philo->philo + 1;
	time = current_time() - philo->main->start;
	// color = color_define(num);
	pthread_mutex_lock(philo->main->m_print);
	if (philo->main->finished != 0)
	{
		pthread_mutex_unlock(philo->main->m_print);
		return ;
	}
	print_statement(num, state, time);
	pthread_mutex_unlock(philo->main->m_print);
}