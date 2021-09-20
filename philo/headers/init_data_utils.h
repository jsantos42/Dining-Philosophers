#ifndef INIT_DATA_UTILS_H
# define INIT_DATA_UTILS_H

# include "main.h"

int	is_input_correct(int argc, char **argv);
int	*import_input_args(int argc, char **argv, t_data *data);
int	import_int(char *str);

#endif
