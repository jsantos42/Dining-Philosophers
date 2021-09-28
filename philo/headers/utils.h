#ifndef UTILS_H
# define UTILS_H

# include "main.h"

int	ft_isdigit(int c);
int	is_in_range_long(long value, long min, long max);
long long get_time(t_data *data);
void	ft_usleep(t_data *data, long long starting_point, int sleeping_time);

#endif
