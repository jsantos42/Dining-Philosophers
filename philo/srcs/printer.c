#include "../headers/printer.h"

void	print_philo_status(t_data *data, int philo_index)
{
	long long	time;
	int			status;
	char		*update;

	time = data->timings.current_time_ms;
	status = data->philo[philo_index].status;
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
	printf("%4lldms	%2d %s.\n", time, philo_index + 1, update);
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
