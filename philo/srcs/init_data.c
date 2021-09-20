#include "../headers/init_data.h"


t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc_or_terminate(NULL, sizeof(t_data));
	if (!is_input_correct(argc, argv))
		terminate_program(data, ILLEGAL_INPUT);
	import_input_args(argc, argv, data);
	data->philo = init_philo(data);
	return (data);
}


t_philo	*init_philo(t_data *data)
{
	int	iter;
	t_philo	*philo;

	iter = -1;
	philo = malloc_or_terminate(data, sizeof(t_philo) * data->nb_philo);
	while (++iter < data->nb_philo)
	{
		philo[iter].id = iter + 1;
		philo[iter].status = THINK;
		philo[iter].next_status_change = 0;
		philo[iter].timings.current_time_ms = 0;
		philo[iter].last_meal_end = 0;
		philo[iter].meal_count = 0;
	}
	return (philo);

}


