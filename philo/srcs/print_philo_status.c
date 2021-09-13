#include "../headers/print_philo_status.h"

void	print_philo_status(int time, int nb_philo, char *action)
{
	printf("%dms	%d %s", time, nb_philo, action);
}
