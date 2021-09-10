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

int	is_int(char *str)
{
	int		sign;
	long	temp;

	sign = 1;
	temp = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		temp *= 10;
		temp += *str++ - '0';
		if (!is_in_range_long(temp * sign, -2147483648, 2147483647))
			return (0);
	}
	if (sign == -1 && temp == 0)
		return (0);
	return (1);
}

int	import_int(char *str)
{
	long	temp;
	int		sign;
	int 	output;

	temp = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '\0')
	{
		temp *= 10;
		temp += *str++ - '0';
	}
	output = (int)temp * sign;
	return (output);
}
