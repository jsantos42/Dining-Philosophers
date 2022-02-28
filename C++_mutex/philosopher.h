#ifndef PHILOSOPHER_PHILOSOPHER_H
#define PHILOSOPHER_PHILOSOPHER_H

#include <mutex>

#define NB_OF_MEALS 5

class philosopher {
public:
	philosopher(const int& new_id, std::mutex *printer);

	void		grabFork(std::mutex* fork, std::mutex* printer);
	void		releaseFork(std::mutex* fork, std::mutex* printer);
	void		eat();
	void		think();
	int			getId();
	int			getMealCount();
	std::mutex*	getPrinterMtx();

private:
	int			id;
	int			meal_count;
	std::mutex	*printer_mtx;
};


#endif //PHILOSOPHER_PHILOSOPHER_H
