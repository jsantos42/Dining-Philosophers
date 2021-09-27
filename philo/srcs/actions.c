#include "../headers/actions.h"

void	take_forks(t_philo *philo)
{
	int first_fork;
	int second_fork;

	if (philo->index % 2)
	{
		first_fork = philo->index;
		second_fork = (philo->index + 1) % philo->data->nb_philo;
	} else
	{
		first_fork = (philo->index + 1) % philo->data->nb_philo;
		second_fork = philo->index;
	}
	pthread_mutex_lock(&philo->data->forks[first_fork]);
	update_status(philo, FIRST_FORK);
	pthread_mutex_lock(&philo->data->forks[second_fork]);
	update_status(philo, SECOND_FORK);
	update_status(philo, EAT);
	philo->last_meal_end = philo->timings.current_time_ms + philo->timings.time_to_eat;
	ft_usleep(philo->timings.time_to_eat);
}

void	go_to_sleep(t_philo *philo)
{
	release_forks(philo);
	philo->meal_count++;
	update_status(philo, SLEEP);
	ft_usleep(philo->timings.time_to_sleep);
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
