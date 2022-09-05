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
	size_t			die;
	size_t			eat;
	size_t			sleep;
	int				needed_meals;
	int				meals;
	size_t			last_meal;
	struct s_all	*main;
}			t_philo;

typedef struct s_all
{
	int		num_philos;
	int		die;
	int		eat;
	int		sleep;
	int		meals;
	int		*forks;
	int		finished;
	size_t	start;
	t_philo	*philo;
	pthread_mutex_t *m_forks;
	pthread_mutex_t *m_check;
	pthread_mutex_t *m_dead;
	pthread_mutex_t *m_print;
}				t_all;

#endif