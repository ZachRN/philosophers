/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_atoi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 13:23:38 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/10 14:23:49 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <limits.h>

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '-')
		return (Too_Small);
	return (Letters);
}

int	philo_atoi(char *str)
{
	long int	num;
	int			error;
	int			i;

	i = 0;
	num = 0;
	while (str[i])
	{
		error = is_num(str[i]);
		if (error < 0)
			return (error);
		num = (num * 10) + (str[i] - '0');
		if (num > INT_MAX)
			return (Too_Big);
		i++;
	}
	if (num == 0)
		return (Too_Small);
	return ((int)(num));
}
