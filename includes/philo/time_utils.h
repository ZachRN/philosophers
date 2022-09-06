/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:06:46 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/06 15:06:47 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include <sys/time.h>

/*Recalculating the time in ms is quite annoying each time, its a 3 line
function, which converts the seconds from gettimeofday into miliseconds and adds
the microseconds which are divided by a thousand to get to miliseconds to get
a medium of miliseconds.*/
size_t	time_in_ms(void);

/*usleep is fairly unpredictable and it can stagger for quite a while
therefore i made my own sleep function, which does still rely on usleep
but i am using gettimeofday() to get a more accurate estimate of how long I have
actually been sleeping for*/
void	my_sleep(size_t miliseconds);

#endif