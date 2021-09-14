#ifndef TYPES_H
# define TYPES_H

# include "main.h"

/*
**	This file contains only the types and defs used on more than one file across
**	the program.
*/

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define MILLISECS_IN_A_SEC 1000

/*
**	ERRORS
*/

typedef enum e_errors {
	ILLEGAL_INPUT				= -1,
	MALLOC_FAILED				= -2,
	GET_TIME_FAILED				= -3,
}	t_errors;

typedef struct timeval	t_timeval;

typedef struct s_time {
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	long long	start_time_ms;
	long long	current_time_ms;
	long long	next_checkpoint_ms;
}	t_timings;

typedef struct s_philo {
	int			id;
	bool		dead;
	long long	last_meal_end;
	long long	next_status_change;
}	t_philo;

typedef struct s_data {
	int			nb_philo;
	t_timings	timings;
	int			must_eat;
	t_philo		*philo;
}	t_data;
#endif
