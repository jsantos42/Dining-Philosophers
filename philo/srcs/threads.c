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
		thread = &data->philos[iter].thread;
		philo = &data->philos[iter];
		if (pthread_create(thread, NULL, run_thread, (void*)philo) != 0)
			return (print_error_message(THREAD_CREATION_FAILED));
	}
	iter = -1;
	while (++iter < data->nb_philo)
	{
		thread = &data->philos[iter].thread;
		philo = &data->philos[iter];
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
		eat_sleep_think_repeat(philo);
	return (NULL);
}


void	eat_sleep_think_repeat(t_philo *philo)
{
	philo->timings.current_time_ms = get_current_time();
	if (philo->timings.current_time_ms >= philo->last_meal_end + philo->timings.time_to_die)
		update_status(philo, DEAD);
	else if (philo->status == SLEEP)
		update_status(philo, THINK);
	else if (philo->status == THINK)
		take_forks(philo);
	else if (philo->status == EAT)
		go_to_sleep(philo);
}
