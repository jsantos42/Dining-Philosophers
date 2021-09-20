#include "../headers/printer.h"

void	print_philo_status(t_philo *philo)
{
	long long	time;
	int			status;
	char		*update;

	time = philo->timings.current_time_ms;
	status = philo->status;
	if (status == THINK)
		update = ft_strdup("is thinking");
	else if (status == FORK)
		update = ft_strdup("has taken a fork");
	else if (status == EAT)
		update = ft_strdup("is eating");
	else if (status == SLEEP)
		update = ft_strdup("is sleeping");
	else
		update = ft_strdup("just died");
	printf("%4lldms	%2d %s.\n", time, philo->id, update);
	free(update);
}

//void	find_dead_philo_and_print(t_data *data)
//{
//	int	iter;
//
//	iter = -1;
//	while (++iter < data->nb_philo)
//	{
//		if (data->philo->status == DEAD)
//		{
//			print_philo_status(data, iter);
//			break;
//		}
//	}
//}
