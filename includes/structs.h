/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:18 by znajda        #+#    #+#                 */
/*   Updated: 2022/09/10 14:39:08 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE 1

/* e_states contains every single state that a Philosopher is able
to be in at any given time*/

enum e_states
{
	Eating = 1,
	Sleeping,
	Thinking,
	Fork,
	Dying
};

/* e_errors contains every error that is possible during parsing. Sent primarily
to print_input_errors to be able to print out the corresponding error messages
Letters, Too_Small, Too_Big are all for Philo_Atoi_H, Malloc && Lock Error
are for mutexs init*/

enum e_errors
{
	Letters = -1,
	Too_Small = -2,
	Too_Big = -3,
	Malloc_Error = -4,
	Lock_Error = -5
};

/* This struct contains all the raw data that the user is able to input to the
program. It is then later converted to individual data to each Philosopher to
avoid having to use extra mutexs to check back to the user input */

typedef struct s_input
{
	int	num_philos;
	int	tt_die;
	int	tt_sleep;
	int	tt_eat;
	int	min_meals;
}				t_input;

/* A nicer naming convention for the type of locks that will be referenced
during the execution of the program, put into an enum for scalabiltiy over a
define */

enum e_mutex
{
	print = 0,
	death
};

/* This contains all mutexs that a Philo will be able to reference, Non_Malloc
states are defined in the enum directly above this comment, where as forks
is one mutex per philosopher entered in the program, needing both in order to
eat and continue the program.

It also contains has_finished, as this is the one variable that all philos
must check, and as it is no internal I decided to put it in the only
external part of the philo, the other struct*/

typedef struct s_mutexs
{
	int				has_finished;
	int				total_finished;
	int				num_philos;
	pthread_mutex_t	non_malloc[2];
	pthread_mutex_t	*forks;
}				t_mutexs;

typedef struct s_philo
{
	int			philo_nbr;
	int			left_fork;
	int			right_fork;
	int			has_eaten;
	int			t_meals;
	size_t		tt_die;
	size_t		tt_sleep;
	size_t		tt_eat;
	size_t		last_eat;
	size_t		program_start;
	t_mutexs	*mutexs;
}				t_philo;

#endif