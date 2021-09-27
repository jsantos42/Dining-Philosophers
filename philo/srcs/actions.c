#include "../headers/actions.h"

void	take_first_fork(t_philo *philo, int first_fork)
{
	take_a_fork(philo, first_fork);
	update_status(philo, FORK);
}

void	take_second_fork_and_eat(t_philo *philo, int second_fork)
{
	take_a_fork(philo, second_fork);
	update_status(philo, FORK);
	update_status(philo, EAT);
	philo->next_status_change = philo->timings.current_time_ms + philo->timings.time_to_eat;
}

int	take_a_fork(t_philo *philo, int fork)
{
	long long	first_time;
	long long	second_time;

	if (!get_current_time(&first_time))
		return (GET_TIME_FAILED);
	pthread_mutex_lock(&philo->data->forks[fork]);
	if (!get_current_time(&second_time))
		return (GET_TIME_FAILED);
	philo->timings.current_time_ms += (second_time - first_time);
	return (1);
}

void	go_to_sleep(t_philo *philo)
{
	release_forks(philo);
	philo->meal_count++;
	philo->last_meal_end = philo->timings.current_time_ms;
	philo->next_status_change = philo->timings.current_time_ms + philo->timings.time_to_sleep;
	update_status(philo, SLEEP);
}

void	release_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->index;
	right_fork = (philo->index + 1) % philo->data->nb_philo;
	pthread_mutex_unlock(&philo->data->forks[left_fork]);
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
}
