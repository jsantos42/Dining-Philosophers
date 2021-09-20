#include "../headers/init_data_utils.h"

static int	is_positive_int(char *str);

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
		if (!is_positive_int(argv[arg_iter]))
			return (0);
	}
	return (1);
}

static int	is_positive_int(char *str)
{
	long	temp;

	temp = 0;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		temp *= 10;
		temp += *str++ - '0';
		if (!is_in_range_long(temp, -2147483648, 2147483647))
			return (0);
	}
	return (1);
}

/*
**	Imports the program arguments (which should all be ints) to a temporary
**	array. In case the optional argument was not provided (meaning, argc is 5
**	instead of 6), sets the last argument as -1.
*/

int	*import_input_args(int argc, char **argv, t_data *data)
{
	int	*input_args;
	int	iter;

	input_args = malloc_or_terminate(data, 4);
	iter = -1;
	while (++iter < argc)
		input_args[iter] = import_int(argv[iter + 1]);
	if (argc == 5)
		input_args[iter] = -1;
}

int	import_int(char *str)
{
	long	temp;
	int		sign;
	int 	output;

	temp = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '\0')
	{
		temp *= 10;
		temp += *str++ - '0';
	}
	output = (int)temp * sign;
	return (output);
}
