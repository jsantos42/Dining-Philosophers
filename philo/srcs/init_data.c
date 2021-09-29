#include "../headers/init_data.h"

int	init_philos(t_data *data, int *input_args)
{
	int	iter;

	data->nb_philo = input_args[NB_PHILO];
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (print_error_message(MALLOC_FAILED));
	data->start_time_ms = get_time();
	data->is_everybody_alive = true;
	iter = -1;
	while (++iter < data->nb_philo)
	{
		data->philos[iter].index = iter;
		data->philos[iter].status = THINK;
		data->philos[iter].time_to_die = input_args[TIME_TO_DIE];
		data->philos[iter].time_to_eat = input_args[TIME_TO_EAT];
		data->philos[iter].time_to_sleep = input_args[TIME_TO_SLEEP];
		data->philos[iter].must_eat = input_args[MUST_EAT];
		data->philos[iter].meal_count = 0;
		data->philos[iter].last_meal_start = data->start_time_ms;
		data->philos[iter].data = data;
		get_fork_order(&data->philos[iter]);
	}
	return (1);
}

/*
**	Initializes the forks variable. Note that, according to the subject, there
**	should be as many forks on the table as there are philosophers. Forks must
**	not be taken by multiple threads at the same time, so this function applies
**	a mutex on them.
*/

int	init_forks(t_data *data)
{
	int	iter;

	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (print_error_message(MALLOC_FAILED));
	iter = -1;
	while (++iter < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[iter], NULL) != 0)
			return (print_error_message(MUTEX_FAILED));
	}
	data->is_fork_available = malloc(data->nb_philo * sizeof(bool));
	if (!data->is_fork_available)
		return (print_error_message(MALLOC_FAILED));
	iter = -1;
	while (++iter < data->nb_philo)
		data->is_fork_available[iter] = true;
	if (pthread_mutex_init(&data->is_everybody_alive_lock, NULL) != 0)
		return (print_error_message(MUTEX_FAILED));
	return (1);
}

/*
**	If each philosopher tries to grab the fork to his left first, there's a tie
**	and no one can actually pick a second fork (since they only release them
**	after finished eating!). As such, some philosophers should try to grab the
**	fork on their left first, while others should try to grab the fork on their
**	right first.
*/

void	get_fork_order(t_philo *philo)
{
	if (philo->index % 2)
	{
		philo->first_fork = philo->index;
		philo->second_fork = (philo->index + 1) % philo->data->nb_philo;
	}
	else
	{
		philo->first_fork = (philo->index + 1) % philo->data->nb_philo;
		philo->second_fork = philo->index;
	}
}
