#include "../headers/threads_utils.h"

/*
**	Checks whether any philosopher is dead.
*/

int	is_everybody_alive(t_data *data)
{
	int	iter;

	iter = -1;
	while (++iter < data->nb_philo)
	{
		if (data->philo[iter].status == DEAD)
			return (0);
	}
	return (1);
}

/*
**	If the must_eat optional argument was given to the program, checks whether
**	all the philosophers had enough meals already.
*/

int	is_anybody_missing_a_meal(t_data *data)
{
	int	iter;

	if (data->must_eat == -1)
		return (1);
	iter = -1;
	while (++iter < data->nb_philo)
	{
		if (data->philo[iter].meal_count < data->must_eat)
			return (1);
	}
	return (0);
}

/*
**	Checks whether the status of the philosopher of index 'index' needs updating
**	and, if so, prints the status update to the terminal.
*/

void	update_status(t_data *data, int index, int new_status)
{
	if (data->philo[index].status != new_status)
	{
		data->philo[index].status = new_status;
		print_philo_status(data, index);
	}
}
