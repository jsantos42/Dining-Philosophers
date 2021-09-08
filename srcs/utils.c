#include "../includes/utils.h"

int	*init_array(int elements)
{
	int	*array;
	int iter;

	array = malloc(elements);
	if (!array)
		error_management(FAILED_MALLOC);
	iter = -1;
	while (++iter < elements)
		array[iter] = 0;
	return (array);
}

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

int	is_int(char *str, int *output)
{
	int		sign;
	long	temp;

	sign = 1;
	temp = 0;
//	if (*str == '-')
//	{
//		sign *= -1;
//		str++;
//	}
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		temp *= 10;
		temp += *str++ - '0';
		if (!is_in_range_long(temp * sign, -2147483648, 2147483647))
			return (0);
	}
//	if (sign == -1 && temp == 0)
//		return (0);
	*output = (int)temp * sign;
	return (1);
}
