#include "../headers/print_philo_status.h"

void	print_philo_status(t_data *data, int nb_philo)
{
	long long	time;
	char	*action;

	time = data->timings.current_time_ms;
	if (action == EAT)
		str = ft_strdup
	action = data->philo[nb_philo - 1].status;
	printf("%4lldms	%2d %s", time, nb_philo, action);
}
# define THINK	"is thinking"
# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
