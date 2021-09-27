#include "../headers/actions.h"

void	try_to_take_fork(t_philo *philo)
{
	if (is_fork_available)
	{
		take_fork(philo);
		if (philo->status == THINK)
			update_status(philo, FORK);
		else
		{
			update_status(philo, EAT);
			philo->next_status_change = philo->timings.current_time_ms + philo->timings.time_to_eat;
		}
	}
}


void	go_to_sleep(t_philo *philo)
{
	philo->meal_count++;
	philo->last_meal_end = philo->timings.current_time_ms;
	philo->next_status_change = philo->timings.current_time_ms + philo->timings.time_to_sleep;
	update_status(philo, SLEEP);
}
