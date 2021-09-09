#include "../headers/main.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = import_input_args(argc, argv);
//	while (no_philosophers_dead)
//	gettimeofday()

//	int i = -1;
//	while (++i < argc)
//		printf("%d\n", vars[i]);

	free(data);
	return 0;
}


