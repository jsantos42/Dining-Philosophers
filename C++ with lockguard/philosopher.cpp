#include <iostream>
#include <csignal>
#include "philosopher.h"

philosopher::philosopher(const int& new_id, std::mutex *printer)
: id(new_id), meal_count(0), printer_mtx(printer)
{}

void	philosopher::eat(std::mutex* first, std::mutex* second)
{
	std::lock_guard<std::mutex> lock_first(*first, std::adopt_lock);
	print(GRAB_FORK);
	std::lock_guard<std::mutex> lock_second(*second, std::adopt_lock);
	print(GRAB_FORK);
	meal_count++;
	print(EAT);
	print(RELEASE_FORK);
	print(RELEASE_FORK);
}

void	philosopher::think()
{
	this->print(THINK);
	usleep(1000000);
}

int 	philosopher::getMealCount()
{
	return (this->meal_count);
}

int	philosopher::getId()
{
	return (this->id);
}

std::mutex*	philosopher::getPrinterMtx()
{
	return (this->printer_mtx);
}

void	philosopher::print(int action)
{
	std::lock_guard<std::mutex> lock_printer(*getPrinterMtx());
	switch (action)
	{
		case GRAB_FORK:
			std::cout << "\033[0;32m""Philosopher " << id << " just grabbed a fork.\n";
		case RELEASE_FORK:
			std::cout << "\033[0;32m""Philosopher " << id << " just released a fork.\n";
		case EAT:
			std::cout << "\033[0;31m""Philosopher " << id << " is eating meal #" << meal_count << ".\n";
		case THINK:
			std::cout << "\033[0;33m""Philosopher " << id << " is thinking.\n";
		default:
			break ;
	}
}
