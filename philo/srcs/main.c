#include "../headers/main.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
//	while (no_philosophers_dead)

	free(data);
	return 0;
}


