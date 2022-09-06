#ifndef INPUT_PARSE_H
# define INPUT_PARSE_H

# include <structs.h>

/* print_input_errors Str takes a string that is the name of the input
that is containing the error, in case of Malloc or Lock Error Null can be
supplied, the integer error_code is any from the enum e_errors in structs_h */

int	print_input_errors(char *str, int error_code);

/* Input returns 0 on Success and 1 on Failure 
Failure will be Not enough arguements, or too many supplied
Failure will also include if any string inputted is flagged
as a error by Philo ATOI, check phil_atoi.h for the specific errors
Only important note is that min_meals is default -1 if no value is entered
as the meal countered will never hit negative to meet the clear condition*/

int	input_parse(int argc, char *argv[], t_input *input);

#endif