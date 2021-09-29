#include "../headers/time_utils.h"

t_timeval	get_time(void)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval);
}

/*
**	The timeval struct (here typedefed as t_timeval) has:
**	  - a value tv_sec which is the number of seconds since Jan. 1, 1970, and
**	  - a tv_usec, which is the microseconds left from that calculation.
**	Hence, time_elapsed sums both (after conversion), giving the number of
**	milliseconds elapsed between the two timeframes passed as arguments.
*/

u_int64_t	time_elapsed(t_timeval start_time, t_timeval end_time)
{
	uint64_t	start_time_ms;
	uint64_t	end_time_ms;

	start_time_ms = start_time.tv_sec * 1000 + (start_time.tv_usec / 1000);
	end_time_ms = end_time.tv_sec * 1000 + (end_time.tv_usec / 1000);
	return (end_time_ms - start_time_ms);
}

void	ft_usleep(t_timeval start_time, uint64_t sleeping_time)
{
	usleep(sleeping_time - sleeping_time / 10);
	while (time_elapsed(start_time, get_time()) <= sleeping_time)
		continue ;
}
