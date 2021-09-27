#include "../headers/threads.h"

/*
**	Starts a thread for each philosopher, each executing the run_thread function
**	with philo as its only argument.
*/

int	start_threads(t_data *data)
{
	int			iter;
	pthread_t	*thread;
	t_philo		*philo;

	iter = -1;
	while (++iter < data->nb_philo)
	{
		thread = &data->philo_thread[iter];
		philo = &data->philos[iter];
		if (pthread_create(thread, NULL, run_thread, philo) != 0)
			return (print_error_message(THREAD_CREATION_FAILED));
		if (pthread_join(*thread, NULL) != 0)
			return (print_error_message(THREAD_JOINING_FAILED));
	}
	return (1);
}

/*
**	This is the function that each thread runs when starting. Runs until the
**	given philosopher is dead or has had enough meals.
**	In each instance, it calculates the next timeframe in which there should be
**	a status change its philosopher.
*/

void	*run_thread(void *philo_cast_to_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_cast_to_void;
	while (is_not_dead(philo) && is_missing_a_meal(philo))
		philo->timings.current_time_ms = get_next_checkpoint(philo);
	return (NULL);
}

/*
**	Gets the next timeframe in which there should be a status change of at least
**	1 philosopher.
*/

long long	get_next_checkpoint(t_philo *philo)
{
	int			status;

	status = philo->status;
	if (philo->timings.current_time_ms == philo->next_status_change
	|| status == THINK || status == FORK)
	{
		if (philo->timings.current_time_ms == philo->last_meal_end + philo->timings.time_to_eat)
			update_status(philo, DEAD);
		else if (status == SLEEP)
			update_status(philo, THINK);
		else if (status == THINK || status == FORK)
			try_to_take_fork(philo);
		else if (status == EAT)
			go_to_sleep(philo);
		if (philo->next_status_change > philo->last_meal_end + philo->timings.time_to_eat)
			philo->next_status_change = philo->last_meal_end + philo->timings.time_to_eat;
	}
	return (philo->next_status_change);
}
