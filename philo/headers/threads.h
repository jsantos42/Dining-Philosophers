#ifndef THREADS_H
# define THREADS_H

# include "main.h"

int		start_threads(t_data *data);
void	*eat_sleep_think_repeat(void *philo_cast_to_void);
void	*check_for_dead(void *data_cast_to_void);

#endif
