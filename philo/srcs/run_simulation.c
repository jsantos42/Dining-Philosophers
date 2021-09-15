#include "../headers/run_simulation.h"

void	run_simulation(t_data *data)
{
	while (!is_everybody_alive(data))
		data->timings.current_time_ms = get_next_checkpoint(data);
	find_dead_philo_and_print(data);
}

long long	get_next_checkpoint(t_data *data)
{
	int	status;
	int	iter;

	iter = -1;
	while (++iter < data->nb_philo)
	{
		status = data->philo[iter].status;
		if (data->philo[iter].next_status_change == data->timings.current_time_ms)
		{
			if (status == THINK)
			{
				check last_finished_eating timeval and add the time_to_eat
				set philo[i].next_checkpoint to that timeframe
				set_flag ready_to_eat
				check if forks available so that he can start eating
				when takes fork, set philo[i].next_checkpoint to that timeframe

			}
			else if (status == FORK)
			{
				check if there is a second fork to pick up

			}
			else if (status == EAT)
			{
				check how much time left to finish eating
				set philo[i].next_checkpoint to that timeframe
			}
			else
			{
				check last_finished_eating timeval and add the time_to_eat
				set philo[i].next_checkpoint to that timeframe
				check how much time left to finish sleeping. If < than the above set:
				set philo[i].next_checkpoint to that timeframe
			}
			data->philo->next_status_change =

					check_each_philo_dying_timeframe_if_starving how much time left to die
		};
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
