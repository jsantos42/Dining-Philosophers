#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include "main.h"

t_timeval	get_time(void);
u_int64_t	time_elapsed(t_timeval start_time, t_timeval end_time);
void		ft_usleep(t_timeval start_time, uint64_t sleeping_time);

#endif
