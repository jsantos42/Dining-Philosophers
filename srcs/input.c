#include "../includes/input.h"

/*
**	Checks if the program arguments are correct. They should be 4 or 5, and all
**	of them should be ints.
**	Note: the argc variable also includes the program name in its count.
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

/*
**	Imports the program arguments (which are all ints) to an array.
*/

int	*import_input_vars(int argc, char **argv)
{
	int	*vars;
	int	iter;

	argv++;
	argc--;
	vars = init_array(5);
	iter = -1;
	while (++iter < argc)
		vars[iter] = import_int(argv[iter]);
	return (vars);
}
