#include <iostream>
#include <csignal>
#include "philosopher.h"

philosopher::philosopher(const int& new_id, std::mutex *printer)
: id(new_id), meal_count(0), printer_mtx(printer)
{}

void	philosopher::eat()
{
	this->meal_count++;
	this->printer_mtx->lock();
	std::cout << "\033[0;31m" << "Philosopher " << this->id
				<< " is eating for the " << this->meal_count << "th time.\n";
	this->printer_mtx->unlock();
	usleep(1000000);
}

void	philosopher::think()
{
	this->printer_mtx->lock();
	std::cout << "\033[0;33m" << "Philosopher " << this->id << " is thinking.\n";
	this->printer_mtx->unlock();
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

void	philosopher::grabFork(std::mutex* fork, std::mutex* printer)
{
	fork->lock();
	this->getPrinterMtx()->lock();
	std::cout << "\033[0;32m" << "Philosopher " << this->getId() << " just grabbed a fork.\n";
	this->getPrinterMtx()->unlock();
}

void	philosopher::releaseFork(std::mutex* fork, std::mutex* printer)
{
	fork->unlock();
	this->getPrinterMtx()->lock();
	std::cout << "\033[0;32m" << "Philosopher " << this->getId() << " just released a fork.\n";
	this->getPrinterMtx()->unlock();
}
