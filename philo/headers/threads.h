#ifndef THREADS_H
# define THREADS_H

# include "main.h"

void	start_threads(t_data *data);
void	*run_thread(void *philo_cast_to_void);
long long	get_next_checkpoint(t_philo *philo);

#endif
