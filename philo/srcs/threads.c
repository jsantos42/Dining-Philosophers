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

	if (pthread_create(&data->dead_checker, NULL, move_timeframe_if_ready, (void*)data) != 0)
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
	while (philo->data->is_everybody_alive && is_missing_a_meal(philo))
	{
		if (philo->data->current_time_ms == philo->next_status_change
		|| philo->status == THINK)
		{
			if (philo->data->current_time_ms >= philo->last_meal_end + philo->time_to_die)
				update_status(philo, DEAD);
			else if (philo->status == THINK)
				try_to_eat(philo);
			else if (philo->status == EAT)
				sleep_and_start_thinking(philo);
			else if (philo->status == SLEEP)
				update_status(philo, THINK);
			if (philo->next_status_change > philo->last_meal_end + philo->time_to_die)
				philo->next_status_change = philo->last_meal_end + philo->time_to_die;
			pthread_mutex_lock(&philo->ready_to_move_lock);
			philo->ready_to_move = true;
			pthread_mutex_unlock(&philo->ready_to_move_lock);
		}
	}
	return (NULL);
}

void	*move_timeframe_if_ready(void *data_cast_to_void)
{
	t_data	*data;
	int		iter;
	int		ready_count;

	data = (t_data *)data_cast_to_void;
	while (1)
	{
		ready_count = 0;
		iter = -1;
		while (++iter < data->nb_philo)
		{
			pthread_mutex_lock(&data->philos[iter].ready_to_move_lock);
			if (data->philos[iter].ready_to_move)
				ready_count++;
			pthread_mutex_unlock(&data->philos[iter].ready_to_move_lock);
		}
		if (ready_count == data->nb_philo)
		{
			// this next line needs to get a function to determinte which is the smaller status change
			data->current_time_ms += 200; //data->philos[0].next_status_change;
			iter = -1;
			while (++iter < data->nb_philo)
			{
				pthread_mutex_lock(&data->philos[iter].ready_to_move_lock);
				data->philos[iter].ready_to_move = false;
				pthread_mutex_unlock(&data->philos[iter].ready_to_move_lock);
			}
		}
	}
}