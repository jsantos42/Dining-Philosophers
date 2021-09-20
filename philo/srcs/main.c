#include "../headers/main.h"

/*
**	Note that exit() is not an allowed function on the subject, which makes it
**	a pain to always return to the main function to quit the program.
*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(argc, argv, &data) < 0)
		return (-1);
	if (start_threads(&data) < 0)
		return (-1);
//	print_philo_status(data, 2);
	free(data);
	return (0);
}
