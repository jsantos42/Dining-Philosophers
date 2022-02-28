#ifndef THREADS_UTILS_H
# define THREADS_UTILS_H

# include "main.h"

int		is_alive(t_philo *philo);
int		is_missing_a_meal(t_philo *philo);
void	update_status(t_philo *philo, int new_status);

#endif
