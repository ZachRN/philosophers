/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_print_status.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 13:18:17 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/10 14:31:46 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <time_utils.h>
#include <colors.h>
#include <stdio.h>

static char	*color_define(int philo)
{
	int	i;

	i = philo % 7;
	if (DEBUG == TRUE)
		return ("\0");
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

int	only_one_philo(t_input input)
{
	char	*color;

	if (input.num_philos != 1)
		return (FALSE);
	color = color_define(1);
	printf("%s%d %d has taken a fork\n", color, 0, 1);
	my_sleep(input.tt_die);
	printf("%s%d %d died\n", color, input.tt_die, 1);
	return (TRUE);
}

void	print_status(t_philo *philo, int state)
{
	size_t	time;
	int		philo_nbr;
	char	*color;

	philo_nbr = philo->philo_nbr + 1;
	pthread_mutex_lock(&philo->mutexs->non_malloc[print]);
	if (philo->mutexs->has_finished != 0)
	{
		pthread_mutex_unlock(&philo->mutexs->non_malloc[print]);
		return ;
	}
	color = color_define(philo_nbr);
	time = time_in_ms() - philo->program_start;
	if (state == Eating)
		printf("%s%zu %d is eating\n", color, time, philo_nbr);
	else if (state == Sleeping)
		printf("%s%zu %d is sleeping\n", color, time, philo_nbr);
	else if (state == Fork)
		printf("%s%zu %d has taken a fork\n", color, time, philo_nbr);
	else if (state == Thinking)
		printf("%s%zu %d is thinking\n", color, time, philo_nbr);
	else if (state == Dying)
		printf("%s%zu %d died\n", color, time, philo_nbr);
	pthread_mutex_unlock(&philo->mutexs->non_malloc[print]);
}
