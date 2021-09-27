#ifndef ACTIONS_H
# define ACTIONS_H

# include "main.h"

void	take_first_fork(t_philo *philo, int first_fork);
void	take_second_fork_and_eat(t_philo *philo, int second_fork);
int	take_a_fork(t_philo *philo, int fork);
void	go_to_sleep(t_philo *philo);
void	release_forks(t_philo *philo);

#endif
