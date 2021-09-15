#include "../headers/terminate_program.h"


void	terminate_program(t_data *data, int error)
{
	free_data(data);
	print_error_message(error);
	exit(error);
}

void	free_data(t_data *data)
{
	if (data)
		free(data);
}

/*
**	Prints the correct error message in the CLI before exiting the program.
*/

void	print_error_message(int error)
{
	printf("ERROR\n");
	if (error == ILLEGAL_INPUT)
	{
		printf("Wrong input. Please run:\n");
		printf("./philo <number_of_philosophers> <time_to_die> <time_to_eat> ");
		printf("<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n");
		printf("Note that the number of philosophers should be at least 1.\n");
	}
	else if (error == MALLOC_FAILED)
		printf("Memory allocation failed.\n");
	else if (error == GET_TIME_FAILED)
		printf("Getting time of day failed.\n");
}
