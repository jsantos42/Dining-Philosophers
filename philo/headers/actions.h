#ifndef ACTIONS_H
# define ACTIONS_H

# include "main.h"

uint64_t	try_to_eat(t_philo *philo);
u_int64_t	sleep_and_start_thinking(t_philo *philo);
int	could_take_fork(t_philo *philo, int fork_index);
void	release_fork(t_philo *philo, int fork_index);

#endif
