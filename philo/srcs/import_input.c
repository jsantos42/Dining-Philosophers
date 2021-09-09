#include "../headers/import_input.h"

/*
**	Imports the program arguments (which should all be ints) to an array.
*/

t_data	*import_input_args(int argc, char **argv)
{
	t_data	*data;

	if (!is_input_correct(argc, argv))
		error_management(ILLEGAL_INPUT);
	data = malloc(sizeof(t_data));
	data->philosophers = import_int(argv[1]);
	data->time_to_die = import_int(argv[2]);
	data->time_to_eat = import_int(argv[3]);
	data->time_to_sleep = import_int(argv[4]);
	if (argc == 6)
		data->must_eat = import_int(argv[5]);
	else
		data->must_eat = -1;
	return (data);
}

/*
**	Checks if the program arguments are correct. They should be 4 or 5, and all
**	of them should be ints.
**	Note1: the argc variable also headers the program name in its count, hence
**	testing if it's between 5 and 6.
**	Note2: the first argument is the program name, hence the arg_iter must start
**	in 0 and not -1.
*/

int	is_input_correct(int argc, char **argv)
{
	int	arg_iter;

	if (argc < 5 || argc > 6)
		return (0);
	arg_iter = 0;
	while (++arg_iter < argc)
	{
		if (!is_int(argv[arg_iter]))
			return (0);
	}
	return (1);
}
