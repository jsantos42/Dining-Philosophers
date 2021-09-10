#ifndef TYPES_H
# define TYPES_H

# include "main.h"

/*
**	This file contains only the types and defs used on more than one file across
**	the program.
*/

/*
**	ERRORS
*/

typedef enum e_errors {
	ILLEGAL_INPUT				= -1,
	MALLOC_FAILED				= -2,
	GET_TIME_FAILED				= -3,
}	t_errors;

typedef struct timeval t_timeval;

typedef struct s_time {
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	t_timeval	start_time;
}	t_timings;

typedef struct s_data {
	int			nb_philo;
	t_timings	timings;
	int			must_eat;
}	t_data;
#endif
