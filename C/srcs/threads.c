#include "../headers/threads.h"

/*
**	Starts a thread for each philosopher, each executing the
**	eat_sleep_think_repeat function with philo as its only argument.
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
		if (pthread_create(thread, NULL, eat_sleep_think_repeat, philo) != 0)
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
*/

void	*eat_sleep_think_repeat(void *philo_cast_to_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_cast_to_void;
	while (philo->status != DEAD && is_missing_a_meal(philo))
	{
		if (time_elapsed(philo->last_meal_start, get_time())
			>= (uint64_t)philo->time_to_die)
			update_status(philo, DEAD);
		else if (philo->status == THINK)
			try_to_eat(philo);
		else if (philo->status == EAT)
			sleep_and_start_thinking(philo);
	}
	return (NULL);
}
