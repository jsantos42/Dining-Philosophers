#ifndef INIT_DATA_UTILS_H
# define INIT_DATA_UTILS_H

# include "main.h"

int	is_input_correct(int argc, char **argv);
int	import_int(char *str);
int	ft_isdigit(int c);
int	is_in_range_long(long value, long min, long max);

#endif
