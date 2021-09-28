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
	data->start_time_ms = 0;
	data->start_time_ms = get_time(data);
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
	uint64_t	sleeping_time;
	uint64_t	first_timeframe;
	uint64_t	second_timeframe;

	philo = (t_philo *)philo_cast_to_void;
	philo->current_time_ms = get_time(philo->data);
	while (philo->data->is_everybody_alive && is_missing_a_meal(philo))
	{
		first_timeframe = get_time(philo->data);
		sleeping_time = 0;
		if (philo->current_time_ms >= philo->last_meal_end + philo->time_to_die)
			update_status(philo, DEAD);
		else if (philo->status == THINK)
			sleeping_time = try_to_eat(philo);
		else if (philo->status == EAT)
			sleeping_time = sleep_and_start_thinking(philo);
		second_timeframe = get_time(philo->data);
		if (sleeping_time)
			philo->current_time_ms += sleeping_time;
		else
			philo->current_time_ms += second_timeframe - first_timeframe;
//		if (second_timeframe < first_timeframe || sleeping_time < 0 || philo->current_time_ms > UINT64_MAX)
//		{
//			printf("thread %d", philo->index + 1);
			printf("2nd: %lld\n", second_timeframe);
			printf("1st: %lld\n", first_timeframe);
			printf("difference: %lld\n", second_timeframe - first_timeframe);
//		printf("changing NOW\n");
			printf("current: %lld\n", philo->current_time_ms);
			printf("sleeping: %lld\n", sleeping_time);
//		printf("current: %lld\n\n\n\n", philo->current_time_ms);
//		printf("current: %lld\n\n\n\n", philo->current_time_ms);
	}
	return (NULL);
}

void	*check_for_dead_philos(void *data_cast_to_void)
{
	t_data	*data;
	int		iter;

	data = (t_data *)data_cast_to_void;
	while (1)
	{
		iter = -1;
		while (++iter < data->nb_philo)
		{
			if (data->philos[iter].current_time_ms >= data->philos[iter].last_meal_end + data->philos[iter].time_to_die)
			{
				update_status(&data->philos[iter], DEAD);
				return (NULL);
			}
		}
	}
}