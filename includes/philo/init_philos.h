/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philos.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 13:25:32 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/07 13:25:40 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_PHILOS_H
# define INIT_PHILOS_H

# include <structs.h>

/* The array of philosophers equal to the number inputted will be created
if the value returned is null there was a malloc error
Otherwise all of the t_input is transferred to each individual philo
so that we do not need to mutex every single individual times and meals*/
t_philo	*init_philos(t_input input, t_mutexs *mutexs);

#endif