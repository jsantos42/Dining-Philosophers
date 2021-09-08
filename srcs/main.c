#include "../includes/main.h"


int	is_input_correct(int argc, char **argv, int **vars)
{
	int	arg_iter;

	if (argc < 5 || argc > 6)
		return (0);
	arg_iter = 0;
	while (++arg_iter < argc)
	{
		if (!is_int(argv[arg_iter], &(*vars)[arg_iter - 1]))
			return (0);
	}
	return (1);
}


int main(int argc, char **argv)
{
	int	*vars;

	vars = init_array(5);
	if (!is_input_correct(argc, argv, &vars))
	{
		free(vars);
		error_management(ILLEGAL_INPUT);
	}

//	int i = 0;
//	while (++i < argc)
//		printf("%d\n", vars[i - 1]);

	free(vars);
	return 0;
}


