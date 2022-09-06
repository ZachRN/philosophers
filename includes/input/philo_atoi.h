#ifndef PHILO_ATOI_H
# define PHILO_ATOI_H

/* Philo ATOI will return positive numbers on success
Zero and Negative numbers returned are treated as Errors
Letters = -1         | To the left are all available error
Too_Small = -2 (< 1) | codes that Philo ATOI is able to return
Too_Big = -3   (INT_MAX)*/

int	philo_atoi(char *str);

#endif