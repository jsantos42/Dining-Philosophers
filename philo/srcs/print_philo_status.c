#include "../headers/print_philo_status.h"

static char    *ft_strdup(const char *s1);
static size_t  ft_strlen(const char *s);
static void    *ft_memcpy(void *dst, const void *src, size_t n);

void	print_philo_status(t_data *data, int nb_philo)
{
	long long	time;
	int			status;
	char		*action;

	time = data->timings.current_time_ms;
	status = data->philo[nb_philo - 1].status;
	if (status == THINK)
		action = ft_strdup("is thinking");
	else if (status == FORK)
		action = ft_strdup("has taken a fork");
	else if (status == EAT)
		action = ft_strdup("is eating");
	else
		action = ft_strdup("is sleeping");
	printf("%4lldms	%2d %s", time, nb_philo, action);
}


static char    *ft_strdup(const char *s1)
{
	char    *s2;
	int     size;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(size);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, size);
	return (s2);
}

static size_t  ft_strlen(const char *s)
{
	size_t  i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void    *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char       *d;
	const unsigned char *s;
	size_t              i;

	d = dst;
	s = src;
	if (d != s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}