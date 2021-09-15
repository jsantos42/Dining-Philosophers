#include "../headers/main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);


	/*
	 * while (no_philosophers is dead)
	 *	read_each_philo_state
 *		check_each_philo_dying_timeframe_if_starving how much time left to die
	 *
	 *
 *	read_philo_state
	if (state == eating)
		check how much time left to finish eating
			set philo[i].next_checkpoint to that timeframe
	else if (state == sleeping)
		check last_finished_eating timeval and add the time_to_eat
			set philo[i].next_checkpoint to that timeframe
		check how much time left to finish sleeping. If < than the above set:
			set philo[i].next_checkpoint to that timeframe
	else if (state == thinking)
		check last_finished_eating timeval and add the time_to_eat
			set philo[i].next_checkpoint to that timeframe
		set_flag ready_to_eat
		check if forks available so that he can start eating
		when takes fork, set philo[i].next_checkpoint to that timeframe
	 */
	data->timings.current_time_ms = 0;
	print_philo_status(data, 2);
	free(data);
	return (0);
}
