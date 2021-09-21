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
}

/*
**	Gets the next timeframe in which there should be a status change of at least
**	1 philosopher.
*/

long long	get_next_checkpoint(t_philo *philo)
{
	long long	current_time;
	long long	next_checkpoint;
	int			status;
	long long	*next_status_change;

	current_time = philo->timings.current_time_ms;
	next_checkpoint = 0;
	next_status_change = &philo->next_status_change;
	status = philo->status;
	if (current_time == *next_status_change)
	{
		if (current_time == philo->last_meal_end + philo->timings.time_to_eat)
		{
			update_status(philo, DEAD);
			return (next_checkpoint);
		}
		if (status == THINK || status == SLEEP)
		{
			if (is_fork_available)
			{
				take_fork(philo);
				update_status(philo, FORK);
				*next_status_change = check_when_forks_will_be_available_next(philo);
			}
			else
				update_status(philo, THINK);
		}
		else if (status == FORK)
		{
			if (is_fork_available)
			{
				take_fork(philo);
				update_status(philo, EAT);
				*next_status_change = current_time + philo->timings.time_to_eat;
			}

		}
		else if (status == EAT)
		{
			philo->last_meal_end = current_time;
			update_status(philo, SLEEP);
			*next_status_change = current_time + philo->timings.time_to_sleep;
		}
		if (*next_status_change > philo->last_meal_end + philo->timings.time_to_eat)
			*next_status_change = philo->last_meal_end + philo->timings.time_to_eat;
		if (!next_checkpoint || next_checkpoint > *next_status_change)
			next_checkpoint = *next_status_change;
	};
	return (next_checkpoint);
}
