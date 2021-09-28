#include "../headers/actions.h"


void	try_to_eat(t_philo *philo)
{
	if (could_take_fork(philo, philo->first_fork))
	{
		if (could_take_fork(philo, philo->second_fork))
		{
			update_status(philo, FIRST_FORK);
			update_status(philo, SECOND_FORK);
			update_status(philo, EAT);
			philo->meal_count++;
			philo->last_meal_end = philo->data->current_time_ms + philo->time_to_eat;
			philo->next_status_change = philo->last_meal_end;
		}
		else
			release_fork(philo, philo->first_fork);
	}
}


int	could_take_fork(t_philo *philo, int fork_index)
{
	bool could_take_a_fork;

	could_take_a_fork = false;
	pthread_mutex_lock(&philo->data->forks[fork_index]);
	if (philo->data->is_fork_available[fork_index])
	{
		philo->data->is_fork_available[fork_index] = false;
		could_take_a_fork = true;
	}
	pthread_mutex_unlock(&philo->data->forks[fork_index]);
	return (could_take_a_fork);
}

void	release_fork(t_philo *philo, int fork_index)
{
	pthread_mutex_lock(&philo->data->forks[fork_index]);
	philo->data->is_fork_available[fork_index] = true;
	pthread_mutex_unlock(&philo->data->forks[fork_index]);
}

void	sleep_and_start_thinking(t_philo *philo)
{
	release_fork(philo, philo->first_fork);
	release_fork(philo, philo->second_fork);
	philo->next_status_change = philo->data->current_time_ms + philo->time_to_sleep;
	update_status(philo, SLEEP);
}


///*
// * function to set the next current time
//*/
//
//void	get_next_checkpoint(t_philo *philo)
//{
//	pthread_mutex_lock(&philo->data->next_chis_everybody_alive_lock);
//
//}