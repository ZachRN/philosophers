/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_individual.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:01:47 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/07 13:32:24 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INDIVIDUAL_H
# define PHILO_INDIVIDUAL_H

# include <structs.h>

/*Philo individual is the routine call for thread creation. This will
give every single individual philo its task of, picking up forks, eating
sleepig, then thinking. Philos only external check is the
philos.mutexs->has_finished to see if the program should terminate for any 
reason. */

void	*individual(void *content);

#endif