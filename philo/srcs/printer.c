#include "../headers/printer.h"

void	print_philo_status(t_philo *philo)
{
	int				status;
	char			*update;

	status = philo->status;
	if (status == THINK)
		update = ft_strdup("is thinking");
	else if (status == FIRST_FORK)
		update = ft_strdup("has taken a fork");
	else if (status == SECOND_FORK)
		update = ft_strdup("has taken another fork");
	else if (status == EAT)
		update = ft_strdup("is eating");
	else if (status == SLEEP)
		update = ft_strdup("is sleeping");
	else
		update = ft_strdup("\x1B[31mjust died");
	printf("%6llu ms	%2d %s.\n", philo->current_time_ms, philo->index + 1, update);
	free(update);
}

/*
**	Prints the correct error message in the CLI before exiting the program.
*/

int	print_error_message(int error)
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
	return (0);
}
