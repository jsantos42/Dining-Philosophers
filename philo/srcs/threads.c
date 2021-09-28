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

	if (pthread_create(&data->dead_checker, NULL, check_for_dead_philos, (void*)data) != 0)
		return (print_error_message(THREAD_CREATION_FAILED));
	iter = -1;
	while (++iter < data->nb_philo)
	{
		thread = &data->philos[iter].thread;
		philo = &data->philos[iter];
		if (pthread_create(thread, NULL, eat_sleep_think_repeat, (void*)philo) != 0)
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
	while (is_alive(philo) && is_missing_a_meal(philo))
	{
//		pthread_mutex_lock(&philo->data->dead_lock);
		if (get_time(philo->data) >= philo->last_meal_end + philo->time_to_die)
		{
//			printf("%lld thread %d is going to be dead\n", get_time(philo->data), philo->index);
			update_status(philo, DEAD);
			break;
		}
		else if (philo->status == THINK)
			try_to_eat(philo);
		else if (philo->status == EAT)
			sleep_and_start_thinking(philo);
//		pthread_mutex_unlock(&philo->data->dead_lock);
	}
	return (NULL);
}

void	*check_for_dead_philos(void *data_cast_to_void)
{
	t_data	*data;
	int		iter;
	long long	time;

	data = (t_data *)data_cast_to_void;
	while (1)
	{
		time = get_time(data);
		iter = -1;
		while (++iter < data->nb_philo)
		{
			if (time >= data->philos[iter].last_meal_end + data->philos[iter].time_to_die)
			{
				update_status(&data->philos[iter], DEAD);
				return (NULL);
			}
		}
	}
}