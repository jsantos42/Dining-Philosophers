#include "../includes/main.h"





int main(int argc, char **argv)
{
	int	*vars;

	if (!is_input_correct(argc, argv))
		error_management(ILLEGAL_INPUT);
	vars = import_input_vars(argc, argv);
//	while (no_philosophers_dead)
	gettimeofday()

	int i = -1;
	while (++i < argc)
		printf("%d\n", vars[i]);

	free(vars);
	return 0;
}


