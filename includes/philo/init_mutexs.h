/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mutexs.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:48:43 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/06 14:48:44 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MUTEXS_H
# define INIT_MUTEXS_H

# include <structs.h>

/*This function cleans all the mutexs within mutexs->fork as that has mutexs
equal to the number of philosophers entered into the program, this function has
a double usage, incase of lock error in the midst of creating them clean_to is
set to the current lock it failed on, on end of program clean up clean_to should
be set to input->num_philos*/
int	lock_clean_up(t_mutexs *mutexs, int clean_to);

/*This function initiates all the mutexs used by the program
exiting on failure either by Malloc or by Lock Error
Input and mutexs are both defined in structs_h*/
int	init_shared_mutexs(t_input input, t_mutexs *mutexs);

#endif