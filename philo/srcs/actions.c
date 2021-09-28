#include "../headers/actions.h"

void	take_forks(t_philo *philo)
{
//	printf("%lld thread %d is trying to eat\n", get_time(philo->data), philo->index);
	pthread_mutex_lock(&philo->data->forks[philo->first_fork]);
	update_status(philo, FIRST_FORK);
	pthread_mutex_lock(&philo->data->forks[philo->second_fork]);
	update_status(philo, SECOND_FORK);
	update_status(philo, EAT);
	philo->last_meal_end = get_time(philo->data) + philo->time_to_eat;
//	printf("%lld thread %d started eating\n",get_time(philo->data),  philo->index);
	ft_usleep(philo->data, philo->time_to_eat);
//	printf("%lld thread %d just ate\n", get_time(philo->data), philo->index);
}

void	sleep_and_start_thinking(t_philo *philo)
{
	release_forks(philo);
	philo->meal_count++;
	update_status(philo, SLEEP);
	ft_usleep(philo->data, philo->time_to_sleep);
	update_status(philo, THINK);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->first_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->second_fork]);
}
