#include "../headers/init_data.h"


t_data	*init_data(int argc, char **argv)
{
	t_data	*data;
	int		*input_args;

	data = malloc_or_terminate(NULL, sizeof(t_data));
	if (!is_input_correct(argc, argv))
		terminate_program(data, ILLEGAL_INPUT);
	input_args = import_input_args(argc, argv);
	data->nb_philo = input_args[NB_PHILO];
	if (data->nb_philo == 0)
	{
		free(input_args);
		terminate_program(data, ILLEGAL_INPUT);
	}
	data->philo = init_philo(data, input_args);
	free(input_args);
	return (data);
}


t_philo	*init_philo(t_data *data, int *input_args)
{
	int	iter;
	t_philo	*philo;

	philo = malloc_or_terminate(data, sizeof(t_philo) * data->nb_philo);
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
	return (philo);
}


