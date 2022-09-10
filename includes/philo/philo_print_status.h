/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_print_status.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:47:56 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/10 14:16:15 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PRINT_STATUS_H
# define PHILO_PRINT_STATUS_H

# include <structs.h>
/*Philo print status is always within another functions "death" lock
This is to gurantee that it will not continue printing messages post death

Running default with the philosopher visualizer will not work as all outfile
will not display color but the code from colors.h If you wish to see it
with the visualizer run the following commands. Running it in DEBUG mode
will display none of the colors.

make fclean
make DEBUG=1
./philo (input here)
*/

void	print_status(t_philo *philo, int state);

int	only_one_philo(t_input input);

#endif