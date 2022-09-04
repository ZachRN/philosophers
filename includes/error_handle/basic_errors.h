/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_errors.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 16:11:43 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/01 16:12:22 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_ERRORS_H
# define BASIC_ERRORS_H

# define SMALL_INT -1
# define INVALID_INT -2
# define BIG_INT -3
# define MALLOC_ERROR -4
# define SUCCESS 1
# define FAILURE 0

# include <structs.h>

int	write_error(char *str, int num);
int	basic_error(int argc);
int	input_error(int argc, char *argv[], t_all *input);

#endif
