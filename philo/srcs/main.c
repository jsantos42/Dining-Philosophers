#include "../headers/main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
//	start_threads
	run_simulation(data);
	data->timings.current_time_ms = 0;
	print_philo_status(data, 2);
	free(data);
	return (0);
}
