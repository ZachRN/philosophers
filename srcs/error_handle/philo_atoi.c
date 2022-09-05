/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_atoi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 15:57:54 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/05 14:07:43 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <basic_errors.h>
#include <limits.h>

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '-')
		return (-1);
	return (-2);
}

int	philo_atoi(char *str)
{
	long int	num;
	int			error;
	int			i;

	i = 0;
	num = 0;
	while(str[i])
	{
		error = is_num(str[i]);
		if (error < 0)
			return (error);
		num = (num  * 10) + (str[i] - '0');
		if (num > INT_MAX)
			return (BIG_INT);
		i++;
	}
	return ((int)(num));
}