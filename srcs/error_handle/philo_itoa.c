/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_itoa.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 15:57:54 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/01 16:04:22 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
		if (num > 2147483647)
			return (-3);
		i++;
	}
	return ((int)(num));
}