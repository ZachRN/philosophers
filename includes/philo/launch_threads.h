/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launch_threads.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 13:25:23 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/07 13:40:04 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCH_THREADS_H
# define LAUNCH_THREADS_H

/*Launch threads will begin to split the philos up and craete the threads
upon a creation error the threads will then clean self up part way through
creation

Launch threads will then wait upon a grim reaper fucntion which sits in main
checking all the threads time to die and meals eaten to come to a conclusion
This is done in a death mutex to prevent data racing by editing and viewing the
same variable in multiple places.
*/

int	launch_threads(t_philo *philos, t_input input);

#endif