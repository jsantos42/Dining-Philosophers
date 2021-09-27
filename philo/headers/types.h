#ifndef TYPES_H
# define TYPES_H

# include "main.h"

/*
**	This file contains only the types and defs used on more than one file across
**	the program.
*/

# define DEAD	-1
# define THINK	0
# define FORK	1
# define EAT	2
# define SLEEP	3
# define MILLISECS_IN_A_SEC 1000

/*
**	ERRORS
*/

typedef enum e_errors {
	ILLEGAL_INPUT				= -1,
	MALLOC_FAILED				= -2,
	THREAD_CREATION_FAILED		= -3,
	THREAD_JOINING_FAILED		= -4,
	MUTEX_FAILED				= -5,
	GET_TIME_FAILED				= -6,
}	t_errors;

typedef struct timeval	t_timeval;

typedef struct s_time {
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	long long	current_time_ms;
}	t_timings;

typedef struct s_philo {
	int				index;
	int				status;
	long long		next_status_change;
	t_timings		timings;
	int				must_eat;
	int				meal_count;
	long long		last_meal_end;
	struct s_data	*data;
}	t_philo;

typedef struct s_data {
	int				nb_philo;
	t_philo			*philos;
	pthread_t		*philo_thread;
	pthread_mutex_t	*forks;
}	t_data;
#endif
