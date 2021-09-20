#ifndef INIT_DATA_H
# define INIT_DATA_H

# include "main.h"

# define NB_PHILO		0
# define TIME_TO_DIE	1
# define TIME_TO_EAT	2
# define TIME_TO_SLEEP	3
# define MUST_EAT		4

int	init_data(int argc, char **argv, t_data *data);
t_philo	*init_philo(t_data *data, int *input_args);

#endif
