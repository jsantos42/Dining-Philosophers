#ifndef THREADS_UTILS_H
# define THREADS_UTILS_H

# include "main.h"

int		is_not_dead(t_philo *philo);
int		is_missing_a_meal(t_philo *philo);
void	update_status(t_philo *philo, int new_status);
void	get_fork_order(t_philo *philo, int *first_fork, int *second_fork);

#endif
