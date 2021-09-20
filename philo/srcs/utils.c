#include "../headers/utils.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_in_range_long(long value, long min, long max)
{
	return (value >= min && value <= max);
}


/*
**	The timeval struct (here typedefed as t_timeval) has:
**	  - a value tv_sec which is the number of seconds since Jan. 1, 1970, and
**	  - a tv_usec, which is the microseconds left from that calculation.
**	Hence, get_current_time sums both before returning a long long value that is
**	the number of milliseconds elapsed from that date.
*/

//long long	get_current_time(t_data *data)
//{
//	t_timeval	timeval;
//	long long	miliseconds;
//
//	if (gettimeofday(&timeval, NULL) == -1)
//		terminate_program(data, GET_TIME_FAILED);
//	miliseconds = timeval.tv_sec * MILLISECS_IN_A_SEC + timeval.tv_usec;
//	return (miliseconds);
//}
