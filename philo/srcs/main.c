#include "../headers/main.h"

static int	import_input_args(int argc, char **argv, int **input_args);
static void	free_memory(t_data *data, int *input_args);

/*
**	Note that exit() is not an allowed function on the subject, which makes it
**	a pain to always return to the main function to quit the program.
*/

int	main(int argc, char **argv)
{
	t_data	data;
	int		*input_args;
	int		ret;

	input_args = NULL;
	ret = 0;
	if (!import_input_args(argc, argv, &input_args)
		|| !init_philos(&data, input_args)
		|| !init_forks(&data)
		|| !start_threads(&data))
		ret = -1;
	free_memory(&data, input_args);
	return (ret);
}

/*
**	Imports the program arguments (which should all be ints) to a temporary
**	array. In case the optional argument was not provided (meaning, --argc is 5
**	instead of 6), sets the last argument as -1.
*/

static int	import_input_args(int argc, char **argv, int **input_args)
{
	int	iter;

	if (!is_input_correct(argc, argv))
		return (print_error_message(ILLEGAL_INPUT));
	*input_args = malloc(5 * sizeof(int));
	if (!*input_args)
		return (print_error_message(MALLOC_FAILED));
	argc--;
	argv++;
	iter = -1;
	while (++iter < argc)
		(*input_args)[iter] = import_int(argv[iter]);
	if (argc == 4)
		(*input_args)[iter] = -1;
	return (1);
}

static void	free_memory(t_data *data, int *input_args)
{
	int	iter;

	if (input_args)
		free(input_args);
	if (data->philos)
		free(data->philos);
	if (data->forks)
	{
		iter = -1;
		while (++iter < data->nb_philo)
			pthread_mutex_destroy(&data->forks[iter]);
		pthread_mutex_destroy(&data->is_everybody_alive_lock);
		free(data->forks);
	}
}
