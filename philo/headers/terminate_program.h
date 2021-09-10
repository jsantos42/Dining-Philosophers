#ifndef TERMINATE_PROGRAM_H
# define TERMINATE_PROGRAM_H

# include "main.h"

void	terminate_program(t_data *data, int error);
void	free_data(t_data *data);
void	print_error_message(int error);

#endif