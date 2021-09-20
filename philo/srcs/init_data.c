#include "../headers/init_data.h"


int	init_data(int argc, char **argv, t_data *data)
{
	int		*input_args;

	if (!import_input_args(argc, argv, &input_args))
		return (print_error_message(ILLEGAL_INPUT));
	data->nb_philo = input_args[NB_PHILO];
	data->philo = init_philo(data, input_args);
	if (!data->philo)
		return (print_error_message(MALLOC_FAILED));
	return (1);
}


t_philo	*init_philo(t_data *data, int *input_args)
{
	int	iter;
	t_philo	*philo;

	philo = NULL;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (philo);
	iter = -1;
	while (++iter < data->nb_philo)
	{
		philo[iter].id = iter + 1;
		philo[iter].status = THINK;
		philo[iter].next_status_change = 0;
		philo[iter].timings.current_time_ms = 0;
		philo[iter].timings.time_to_die = input_args[TIME_TO_DIE]];
		philo[iter].timings.time_to_eat = input_args[TIME_TO_EAT];
		philo[iter].timings.time_to_sleep = input_args[TIME_TO_SLEEP];
		philo[iter].must_eat = input_args[MUST_EAT];
		philo[iter].last_meal_end = 0;
		philo[iter].meal_count = 0;
	}
	free(input_args);
	return (philo);
}
