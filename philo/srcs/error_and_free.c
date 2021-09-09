#include "../headers/error_and_free.h"

/*
**	Prints the correct error message in the CLI before exiting the program.
*/

void	error_management(int error)
{
	printf("ERROR\n");
	if (error == ILLEGAL_INPUT)
	{
		printf("Wrong input. Please run:\n");
		printf("./philo <number_of_philosophers> <time_to_die> <time_to_eat> ");
		printf("<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n");
	}
	else if (error == FAILED_MALLOC)
		printf("Memory allocation failed.\n");
	exit(error);
}
