#include "../headers/main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
//	start_threads
	run_simulation(data);
	print_philo_status(data, 2);
	free(data);
	return (0);
}
