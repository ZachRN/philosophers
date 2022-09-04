#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0

enum e_states 
{
	Eating = 1,
	Sleeping,
	Thinking,
	Grab_Fork,
	Died,
	Over
};

typedef struct s_philo
{
	int				philo;
	int				fork_left;
	int				fork_right;
	int				has_left;
	int				has_right;
	int				meals;
	size_t			last_meal;
	struct s_all	*main;
}			t_philo;

typedef struct s_all
{
	int		num_philos;
	size_t		die;
	size_t		eat;
	size_t		sleep;
	int		meals;
	int		*forks;
	int		finished;
	size_t	start;
	t_philo	*philo;
	pthread_mutex_t *check;
	pthread_mutex_t *dead;
	pthread_mutex_t *print;
}				t_all;

#endif