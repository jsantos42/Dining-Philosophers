#include "../headers/init_data.h"

t_philo	*init_philo(t_data *data);
static int	is_input_correct(int argc, char **argv);
static void	import_input_args(int argc, char **argv, t_data *data);

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc_or_terminate(NULL, sizeof(t_data));
	if (!is_input_correct(argc, argv))
		terminate_program(data, ILLEGAL_INPUT);
	import_input_args(argc, argv, data);
	data->timings.start_time_ms = 0;
	data->philo = init_philo(data);
//	data->timings.start_time_ms = get_current_time(data);
//	usleep(700);
//	data->timings.current_time_ms = get_current_time(data);
//	printf("%lld\n", data->timings.current_time_ms - data->timings.start_time_ms);

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
		philo[iter].dead = false;
		philo[iter].last_meal_end = 0;
		philo[iter].meal_count = 0;
		philo[iter].next_status_change = 0;
		philo[iter].status = THINK;
	}
	return (philo);

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
		if (!is_positive_int(argv[arg_iter]))
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
	if (data->nb_philo == 0)
		terminate_program(data, ILLEGAL_INPUT);
	data->timings.time_to_die = import_int(argv[2]);
	data->timings.time_to_eat = import_int(argv[3]);
	data->timings.time_to_sleep = import_int(argv[4]);
	if (argc == 6)
		data->must_eat = import_int(argv[5]);
	else
		data->must_eat = -1;
}

/*
**	The timeval struct (here typedefed as t_timeval) has:
**	  - a value tv_sec which is the number of seconds since Jan. 1, 1970, and
**	  - a tv_usec, which is the microseconds left from that calculation.
**	Hence, get_current_time sums both before returning a long long value that is
**	the number of milliseconds elapsed from that date.
*/

long long	get_current_time(t_data *data)
{
	t_timeval	timeval;
	long long	miliseconds;

	if (gettimeofday(&timeval, NULL) == -1)
		terminate_program(data, GET_TIME_FAILED);
	miliseconds = timeval.tv_sec * MILLISECS_IN_A_SEC + timeval.tv_usec;
	return (miliseconds);
}
