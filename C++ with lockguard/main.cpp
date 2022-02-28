#include <iostream>
#include <thread>
#include <mutex>
#include "philosopher.h"


void	initPhilo(int i, std::mutex* left, std::mutex* right, std::mutex* printer)
{
	philosopher	philo(i, printer);

	while (philo.getMealCount() < NB_OF_MEALS)
	{
		if (philo.getId() % 2)
			philo.eat(left, right);
		else
			philo.eat(right, left);
		philo.think();
	}
}

void runSimulation (int nb_philo) {
	std::thread	threads[nb_philo];
	std::mutex	mtx[nb_philo];
	std::mutex	*left;
	std::mutex	*right;
	std::mutex	printer;
	int			i;

	for (i = 0; i < nb_philo; i++)
	{
		if (i == 0)
			left = &mtx[nb_philo - 1];
		else
			left = &mtx[i - 1];
		right = &mtx[i];
		threads[i] = std::thread(initPhilo, i, left, right, &printer);
	}
	for (i = 0; i < nb_philo; i++)
		threads[i].join();
}

int main() {
	int	nb_philo;

	std::cout << "Please provide a number of philosophers to run the sim.\n";
	std::cin >> nb_philo;
	while (std::cin.fail() || nb_philo < 2 || nb_philo > 10)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "\nWrong input.\n"
				  << "Please provide a number between 2 and 10.\n";
		std::cin >> nb_philo;
	}
	runSimulation(nb_philo);
	return (0);
}