#include "../headers/init_data.h"

static int	is_input_correct(int argc, char **argv);
static void	import_input_args(int argc, char **argv, t_data *data);
static void	get_start_time(t_data *data);


t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!is_input_correct(argc, argv))
		terminate_program(data, ILLEGAL_INPUT);
	import_input_args(argc, argv, data);
	get_start_time(data);
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

static int	is_input_correct(int argc, char **argv)
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

/*
**	Imports the program arguments (which should all be ints) to the struct.
*/

static void	import_input_args(int argc, char **argv, t_data *data)
{
	data->nb_philo = import_int(argv[1]);
	data->timings.time_to_die = import_int(argv[2]);
	data->timings.time_to_eat = import_int(argv[3]);
	data->timings.time_to_sleep = import_int(argv[4]);
	if (argc == 6)
		data->must_eat = import_int(argv[5]);
	else
		data->must_eat = -1;
}

static void	get_start_time(t_data *data)
{
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		terminate_program(data, GET_TIME_FAILED);
	data->timings.start_time = time;
}
