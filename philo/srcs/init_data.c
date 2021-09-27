#include "../headers/init_data.h"


int	init_data(int argc, char **argv, t_data *data)
{
	int		*input_args;

	if (!import_input_args(argc, argv, &input_args))
		return (print_error_message(ILLEGAL_INPUT));
	data->nb_philo = input_args[NB_PHILO];
	data->philos = init_philos(data, input_args);
	if (!data->philos)
		return (-1);
	data->forks = init_forks(data);
	if (!data->forks)
		return (-1);
	//printer_mutex??
	return (1);
}


t_philo	*init_philos(t_data *data, int *input_args)
{
	t_philo	*philos;
	int		iter;

	philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philos)
	{
		print_error_message(MALLOC_FAILED);
		return (NULL);
	}
	iter = -1;
	while (++iter < data->nb_philo)
	{
		philos[iter].index = iter;
		philos[iter].status = THINK;
		philos[iter].next_status_change = 0;
		philos[iter].timings.current_time_ms = 0;
		philos[iter].timings.time_to_die = input_args[TIME_TO_DIE];
		philos[iter].timings.time_to_eat = input_args[TIME_TO_EAT];
		philos[iter].timings.time_to_sleep = input_args[TIME_TO_SLEEP];
		philos[iter].must_eat = input_args[MUST_EAT];
		philos[iter].last_meal_end = 0;
		philos[iter].meal_count = 0;
		philos[iter].data = data;
	}
	free(input_args);
	return (philos);
}

/*
**	Initializes the forks variable. Note that, according to the subject, there
**	should be as many forks on the table as there are philosophers. Forks must
**	not be taken by multiple threads at the same time, so this function applies
**	a mutex on them.
*/

pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t *forks;
	int 			iter;

	forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!forks)
	{
		free(data->philos);
		print_error_message(MALLOC_FAILED);
		return (NULL);
	}
	iter = -1;
	while (++iter < data->nb_philo)
	{
		if (pthread_mutex_init(&forks[iter], NULL) != 0)
		{
			free(data->philos);
			free(forks);
			print_error_message(MUTEX_FAILED);
			return (NULL);
		}
	}
	return (forks);
}