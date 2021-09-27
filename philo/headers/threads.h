#ifndef THREADS_H
# define THREADS_H

# include "main.h"

int	start_threads(t_data *data);
void	*run_thread(void *philo_cast_to_void);
void	eat_sleep_think_repeat(t_philo *philo);
long long	get_next_checkpoint(t_philo *philo);

#endif
