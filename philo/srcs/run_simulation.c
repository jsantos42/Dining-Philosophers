#include "../headers/run_simulation.h"

void	update_status(t_data *data, int philo_index, int new_status);

void	run_simulation(t_data *data)
{
	while (!is_everybody_alive(data))
		data->timings.current_time_ms = get_next_checkpoint(data);
//	find_dead_philo_and_print(data);
}

long long	get_next_checkpoint(t_data *data)
{
	int			iter;
	long long	current_time;
	long long	next_checkpoint;
	int			status;
	long long	*next_status_change;

	iter = -1;
	current_time = data->timings.current_time_ms;
	next_checkpoint = 0;
	while (++iter < data->nb_philo)
	{
		next_status_change = &data->philo[iter].next_status_change;
		status = data->philo[iter].status;
		if (current_time == *next_status_change)
		{
			if (current_time == data->philo[iter].last_meal_end + data->timings.time_to_eat)
			{
				update_status(data, iter, DEAD);
				break ;
			}
			if (status == THINK || status == SLEEP)
			{
				if (is_fork_available)
				{
					take_fork(data);
					update_status(data, iter, FORK);
					*next_status_change = check_when_forks_will_be_available_next(data);
				}
				else
					update_status(data, iter, THINK);
			}
			else if (status == FORK)
			{
				if (is_fork_available)
				{
					take_fork(data);
					update_status(data, iter, EAT);
					*next_status_change = current_time + data->timings.time_to_eat;
				}

			}
			else if (status == EAT)
			{
				data->philo[iter].last_meal_end = current_time;
				update_status(data, iter, SLEEP);
				*next_status_change = current_time + data->timings.time_to_sleep;
			}
			if (*next_status_change > data->philo->last_meal_end + data->timings.time_to_eat)
				*next_status_change = data->philo->last_meal_end + data->timings.time_to_eat;
			if (!next_checkpoint || next_checkpoint > *next_status_change)
				next_checkpoint = *next_status_change;
		};
	}
	return (next_checkpoint);
}



void	update_status(t_data *data, int philo_index, int new_status)
{
	int	*current_status;

	current_status = &data->philo[philo_index].status;
	if (*current_status != new_status)
	{
		*current_status = new_status;
		print_philo_status(data, philo_index);
	}
}

int	is_everybody_alive(t_data *data)
{
	int	iter;

	iter = -1;
	while (++iter < data->nb_philo)
	{
		if (data->philo->status == DEAD)
			return (0);
	}
	return (1);
}
