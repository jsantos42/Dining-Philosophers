#include "../includes/main.h"


int	is_input_corret(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}


int main(int argc, char **argv)
{
	if (!is_input_corret(argc, argv))
		error_management(ILLEGAL_INPUT);



	printf("Hello, World!\n");
	return 0;
}
